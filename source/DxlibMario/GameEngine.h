#pragma once
#include "smart_ptr.h"
#include <map>
#include <list>
#include <string>

PTR( GameEngine );
PTR( Renderer );
PTR( Process );
PTR( Input );
PTR( Sprite );
PTR( GameObject );
PTR( Camera );
PTR( SpriteRenderer );
PTR( AnimationClip );
PTR( GameTime );

class GameEngine {

friend class SpriteRenderer; // for layer setup
public:
	static GameEnginePtr GetInstance();
	virtual ~GameEngine();

	//               guid
	typedef std::map<int, SpriteRendererPtr> SpriteMap;

	SpritePtr LoadSprite(const char* filename);

	AnimationClipPtr CreateAnimationClip(const char* name);

	GameObjectPtr CreateGameObject();
	CameraPtr CreateCamera();

	RendererPtr GetRenderer();
	InputPtr GetInput();
	ProcessPtr GetProcess();
	GameTimePtr GetGameTime();

	CameraPtr GetMainCamera();

	// get all object in game
	const std::map<int, GameObjectPtr>& GetGameObjects();
	// remove object in game, fist remove in scene and put to wait list,  will destroy in the end of frame
	void DestroyObject(GameObjectPtr obj);
	//main loop
	void Run();
private:
	GameEngine();
	void UpdateObject();
	void RenderObject();
	void RenderSprite();
	void CheckCollision();

	//really free the memory of the objects waiting to destroy
	void DeleteObjects();

	// only call by spriterenderer
	void SetSpritetLayer(int layer, SpriteRendererPtr renderer);
	void ClearSpritetLayer(int layer, int guid);
private:
	static GameEnginePtr _instance;

	RendererPtr _renderer;
	InputPtr _input;
	ProcessPtr _process;
	CameraPtr _mainCamera;
	GameTimePtr _gameTime;

	struct SpriteData {
		int num;
		int width;
		int height;
	};
	//       filename
	std::map<std::string, SpriteData> _sprites;
	//      guid
	std::map<int, GameObjectPtr> _objects;
	std::map<int, GameObjectPtr> _waitForDelete;

	//       layer
	std::map<int, SpriteMap> _layerSprite;
	//       clip name
	std::map<std::string, AnimationClipPtr> _clips;
};

#define sGameEngine GameEngine::GetInstance()