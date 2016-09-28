#pragma once
#include "smart_ptr.h"
#include <map>

PTR( GameEngine );
PTR( Renderer );
PTR( Sprite );
PTR( GameObject );

class GameEngine {
public:
	static GameEnginePtr GetInstance();
	virtual ~GameEngine();

	SpritePtr LoadSprite(const char* filename);
	GameObjectPtr CreateGameObject();
private:
	GameEngine();
	static GameEnginePtr _instance;

private:
	RendererPtr _renderer;
	std::map<const char*, SpritePtr> _sprites;
	std::map<int, GameObjectPtr> _objects;
};

#define sGame GameEngine::GetInstance()