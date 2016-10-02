#pragma once
#include "smart_ptr.h"
#include <map>
#include <list>

PTR( GameEngine );
PTR( Renderer );
PTR( Process );
PTR( Input );
PTR( Sprite );
PTR( GameObject );
PTR( Camera );
PTR( SpriteRenderer );

class GameEngine {

friend class SpriteRenderer;
public:
	static GameEnginePtr GetInstance();
	virtual ~GameEngine();

	//               guid
	typedef std::map<int, SpriteRendererPtr> SpriteMap;

	SpritePtr LoadSprite(const char* filename);

	GameObjectPtr CreateGameObject();
	CameraPtr CreateCamera();

	RendererPtr GetRenderer();
	InputPtr GetInput();
	ProcessPtr GetProcess();

	CameraPtr GetMainCamera();

	const std::map<int, GameObjectPtr>& GetGameObjects();

	void DestroyObject(GameObjectPtr obj);

	void Run();
private:
	GameEngine();
	void UpdateObject();
	void RenderObject();
	void RenderSprite();
	void CheckCollider();

	void DeleteObjects();

	void SetSpritetLayer(int layer, SpriteRendererPtr renderer);
	void ClearSpritetLayer(int layer, int guid);
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
	std::map<int, GameObjectPtr> _waitForDelete;

	//       layer
	std::map<int, SpriteMap> _layerSprite;
};

#define sGameEngine GameEngine::GetInstance()