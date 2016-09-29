#pragma once
#include "smart_ptr.h"
#include <map>

PTR( GameEngine );
PTR( Renderer );
PTR( Process );
PTR( Input );
PTR( Sprite );
PTR( GameObject );
PTR( Camera );

class GameEngine {
public:
	static GameEnginePtr GetInstance();
	virtual ~GameEngine();

	SpritePtr LoadSprite(const char* filename);

	GameObjectPtr CreateGameObject();
	CameraPtr CreateCamera();

	RendererPtr GetRenderer();
	InputPtr GetInput();
	ProcessPtr GetProcess();

	CameraPtr GetMainCamera();

	void Run();
private:
	GameEngine();
	void UpdateObject();
	void RenderObject();

private:
	static GameEnginePtr _instance;

	RendererPtr _renderer;
	InputPtr _input;
	ProcessPtr _process;
	CameraPtr _mainCamera;
	std::map<const char*, SpritePtr> _sprites;
	std::map<int, GameObjectPtr> _objects;
};

#define sGameEngine GameEngine::GetInstance()