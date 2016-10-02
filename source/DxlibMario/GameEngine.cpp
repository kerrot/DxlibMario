#include "GameEngine.h"
#include "Sprite.h"
#include "Renderer.h"
#include "DxlibRenderer.h"
#include "Input.h"
#include "DxlibInput.h"
#include "Process.h"
#include "DxlibProcess.h"
#include "GameObject.h"
#include "Camera.h"
#include "SpriteRenderer.h"
#include "SpriteCollider.h"

GameEnginePtr GameEngine::_instance;


GameEngine::GameEngine( ) 
: _renderer(DxlibRendererPtr(new DxlibRenderer))
, _input(DxlibInputPtr(new DxlibInput)) 
, _process(DxlibProcessPtr(new DxlibProcess)){
	CreateCamera();
}


GameEngine::~GameEngine( ) {
	
}

SpritePtr GameEngine::LoadSprite(const char * filename)
{
	std::map<const char*, SpritePtr>::const_iterator iter = _sprites.find(filename);
	if (iter != _sprites.end())
	{
		return iter->second;
	}

	int num = _renderer->LoadSprite(filename);
	int width;
	int height;
	_renderer->GetSpriteSize(num, &width, &height);

	SpritePtr tmp = SpritePtr(new Sprite(num, width, height));
	_sprites[filename] = tmp;

	return tmp;
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
		DeleteObjects();

		_input->UpdateKey();

		CheckCollider();

		UpdateObject();

		_renderer->Clear();
		RenderObject();
		_renderer->Flip();
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