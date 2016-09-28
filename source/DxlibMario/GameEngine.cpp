#include "GameEngine.h"
#include "Sprite.h"
#include "Renderer.h"
#include "DxlibRenderer.h"
#include "GameObject.h"

GameEnginePtr GameEngine::_instance;


GameEngine::GameEngine( ) {

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

	SpritePtr tmp = SpritePtr(new Sprite(filename, _renderer->LoadGraph(filename)));
	_sprites[filename] = tmp;

	return tmp;
}

GameObjectPtr GameEngine::CreateGameObject() {
	GameObjectPtr tmp = GameObjectPtr(new GameObject());
	_objects[tmp->GetGuid()] = tmp;

	return tmp;
}


GameEnginePtr GameEngine::GetInstance( ) {
	if ( !_instance ) {
		_instance = GameEnginePtr(new GameEngine);
	}

	return _instance;
}