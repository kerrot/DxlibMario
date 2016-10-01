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
PTR( SpriteRenderer );

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

	const std::map<int, GameObjectPtr>& GetGameObjects();

	void Run();
private:
	GameEngine();
	void UpdateObject();
	void RenderObject();
	void RenderSprite();
	void CheckCollider();

	friend class SpriteRenderer;
	void SetLayer(int layer, SpriteRendererPtr renderer);
private:
	static GameEnginePtr _instance;

	RendererPtr _renderer;
	InputPtr _input;
	ProcessPtr _process;
	CameraPtr _mainCamera;

	//       filename
	std::map<const char*, SpritePtr> _sprites;
	//      guid
	std::map<int, GameObjectPtr> _objects;

	//               guid
	typedef std::map<int, SpriteRendererPtr> SpriteMap;
	//       layer
	std::map<int, SpriteMap> _layerSprite;
};

#define sGameEngine GameEngine::GetInstance()