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

	SpritePtr tmp = SpritePtr(new Sprite(_renderer->LoadSprite(filename)));
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

void GameEngine::Run() {
	while(!_input->GetKey("ESC") && _process->WindowMessage() == 0) {
		_input->UpdateKey();

		UpdateObject();

		_renderer->Clear();

		RenderObject();

		_renderer->Flip();
	}
}

void GameEngine::UpdateObject() {
	for (std::map<int, GameObjectPtr>::iterator iter = _objects.begin();
		iter != _objects.end(); ++iter ) {
		iter->second->Update();
	}

	for (std::map<int, GameObjectPtr>::iterator iter = _objects.begin();
		iter != _objects.end(); ++iter) {
		iter->second->LastUpdate();
	}
}

void GameEngine::RenderObject() {
	for (std::map<int, GameObjectPtr>::iterator iter = _objects.begin();
		iter != _objects.end(); ++iter ) {
		iter->second->Render();
	}
}