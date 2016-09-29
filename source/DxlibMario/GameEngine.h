#pragma once
#include "smart_ptr.h"
#include <map>

PTR( GameEngine );
PTR( Renderer );
PTR( Input );
PTR( Sprite );
PTR( GameObject );

class GameEngine {
public:
	static GameEnginePtr GetInstance();
	virtual ~GameEngine();

	SpritePtr LoadSprite(const char* filename);
	GameObjectPtr CreateGameObject();

	RendererPtr GetRenderer();
	InputPtr GetInput();

	void Run();
private:
	GameEngine();
	void UpdateObject();
	void RenderObject();

private:
	static GameEnginePtr _instance;

	RendererPtr _renderer;
	InputPtr _input;
	std::map<const char*, SpritePtr> _sprites;
	std::map<int, GameObjectPtr> _objects;
};

#define sGameEngine GameEngine::GetInstance()