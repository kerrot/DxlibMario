#include "GameEngine.h"
#include "Sprite.h"
#include "Renderer.h"
#include "DxlibRenderer.h"
#include "DxlibInput.h"
#include "DxlibGameTime.h"
#include "DxlibProcess.h"
#include "GameObject.h"
#include "Camera.h"
#include "SpriteRenderer.h"
#include "SpriteCollider.h"
#include "AnimationClip.h"


GameEnginePtr GameEngine::_instance;


GameEngine::GameEngine( ) 
: _renderer(DxlibRendererPtr(new DxlibRenderer))
, _input(DxlibInputPtr(new DxlibInput)) 
, _process(DxlibProcessPtr(new DxlibProcess))
,_gameTime(DxlibGameTimePtr(new DxlibGameTime)){
	CreateCamera();
}


GameEngine::~GameEngine( ) {
	
}

SpritePtr GameEngine::LoadSprite(const char * filename)
{
	std::map<std::string, SpriteData>::const_iterator iter = _sprites.find(filename);
	if (iter != _sprites.end())
	{
		return SpritePtr(new Sprite(iter->second.num, iter->second.width, iter->second.height));
	}

	SpriteData data;
	data.num = _renderer->LoadSprite(filename);
	_renderer->GetSpriteSize(data.num, &data.width, &data.height);
	_sprites[filename] = data;

	return SpritePtr(new Sprite(data.num, data.width, data.height));
}

GameObjectPtr GameEngine::CreateGameObject() {
	GameObjectPtr tmp = GameObjectPtr(new GameObject());
	_objects[tmp->GetGuid()] = tmp;

	return tmp;
}

CameraPtr GameEngine::CreateCamera() {
	CameraPtr tmp = CameraPtr(new Camera());
	_objects[tmp->GetGuid()] = tmp;

	if (!_mainCamera)
	{
		_mainCamera = tmp;
	}

	return tmp;
}

AnimationClipWPtr GameEngine::CreateAnimationClip(const char* name) {
	std::map<std::string, AnimationClipPtr>::iterator iter = _clips.find(name);
	if (iter != _clips.end()) {
		return iter->second;
	}

	AnimationClipPtr tmp = AnimationClipPtr(new AnimationClip(name));
	_clips[name] = tmp;

	return tmp;
}

GameEnginePtr GameEngine::GetInstance( ) {
	if ( !_instance ) {
		_instance = GameEnginePtr(new GameEngine);
	}

	return _instance;
}

RendererPtr GameEngine::GetRenderer() {
	return _renderer;
}

InputPtr GameEngine::GetInput() {
	return _input;
}


ProcessPtr GameEngine::GetProcess() {
	return _process;
}

GameTimePtr GameEngine::GetGameTime() {
	return _gameTime;
}

CameraPtr GameEngine::GetMainCamera() {
	return _mainCamera;
}

const std::map<int, GameObjectPtr>& GameEngine::GetGameObjects() {
	return _objects;
}

void GameEngine::DestroyObject(GameObjectPtr obj) {
	if (obj) {
		std::map<int, GameObjectPtr>::iterator iter = _objects.find(obj->GetGuid());
		if (iter != _objects.end()) {
			_waitForDelete[iter->second->GetGuid()] = iter->second;
		}
	}
}

void GameEngine::Run() {
	while(!_input->GetKey("ESC") && _process->WindowMessage() == 0) {
		
		_gameTime->UpdateTime();

		_input->UpdateKey();

		CheckCollider();

		UpdateObject();

		_renderer->Clear();
		RenderObject();
		_renderer->Flip();

		DeleteObjects();
	}
}

void GameEngine::UpdateObject() {
	for (std::map<int, GameObjectPtr>::iterator iter = _objects.begin();
		iter != _objects.end(); ++iter ) {
		if (iter->second->IsEnabled()) {
			iter->second->Update();
		}
	}

	for (std::map<int, GameObjectPtr>::iterator iter = _objects.begin();
		iter != _objects.end(); ++iter) {
		if (iter->second->IsEnabled()) {
			iter->second->LastUpdate();
		}
	}
}

void GameEngine::RenderObject() {
	for (std::map<int, GameObjectPtr>::iterator iter = _objects.begin();
		iter != _objects.end(); ++iter ) {
		if (iter->second->IsEnabled()) {
			iter->second->Render();
		}
	}

	RenderSprite();
}

void GameEngine::RenderSprite() {
	for (std::map<int, SpriteMap>::iterator iter = _layerSprite.begin();
		iter != _layerSprite.end(); ++iter) {
		
		for (SpriteMap::iterator spriteIter = iter->second.begin();
			spriteIter != iter->second.end(); ++spriteIter) {
			
			if (spriteIter->second->IsEnabled()) {
				spriteIter->second->RenderSprite();
			}
		}
	}
}

void GameEngine::CheckCollider() {
	for (std::map<int, GameObjectPtr>::iterator iter1 = _objects.begin();
		iter1 != _objects.end(); ++iter1) {
		
		if (iter1->second->IsEnabled()) {
			std::map<int, GameObjectPtr>::iterator iter2 = iter1;
			for (++iter2; iter2 != _objects.end(); ++iter2) {

				if (iter2->second->IsEnabled() &&
					iter1->second->_collider && iter1->second->_collider->IsEnabled() &&
					iter2->second->_collider && iter2->second->_collider->IsEnabled()) {
						Rect rect1(iter1->second->_collider->GetRect()), rect2(iter2->second->_collider->GetRect());
						rect1.Shift((int)iter1->second->GetGlobalPosition().x, (int)iter1->second->GetGlobalPosition().y);
						rect2.Shift((int)iter2->second->GetGlobalPosition().x, (int)iter2->second->GetGlobalPosition().y);

						if (Rect::IsCollision(rect1, rect2)) {

							GameObjectCollision(iter1->second, iter2->second);
							GameObjectCollision(iter2->second, iter1->second);
							break;
						}
				}
			}
		}
	}
}

void GameEngine::DeleteObjects() {
	for (std::map<int, GameObjectPtr>::iterator iter = _waitForDelete.begin();
		iter != _waitForDelete.end(); ++iter) {

		iter->second->Destroy();

		_objects.erase(_objects.find(iter->first));
	}

	_waitForDelete.clear();
}

void GameEngine::SetSpritetLayer(int layer, SpriteRendererPtr renderer) {
	if (!renderer) {
		return;
	}

	int guid = renderer->GetGameObject()->GetGuid();
	GameEngine::SpriteMap& map = _layerSprite[renderer->GetLayer()];
	GameEngine::SpriteMap::iterator iter = map.find(guid);
	if (iter != map.end())
	{
		map.erase(iter);
	}

	_layerSprite[layer][guid] = renderer;
}

void GameEngine::ClearSpritetLayer(int layer, int guid) {
	GameEngine::SpriteMap& map = _layerSprite[layer];
	GameEngine::SpriteMap::iterator iter = map.find(guid);
	if (iter != map.end())
	{
		map.erase(iter);
	}
}