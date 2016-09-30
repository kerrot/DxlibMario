#include "Game.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "Renderer.h"
#include "Camera.h"
#include "CameraControl.h"

GamePtr Game::_instance;


Game::Game( ) {
	
}


Game::~Game( ) {
	
}


GamePtr Game::GetInstance( ) {
	if ( !_instance ) {
		_instance = GamePtr(new Game);
	}

	return _instance;
}

void Game::Init() {
	sRenderer->SetFullWindow(false);

	//BG
	GameObjectPtr obj = sGameEngine->CreateGameObject();
	SpriteRendererPtr spriteRenderer = obj->AddSpriteRenderer();
	spriteRenderer->SetLayer(-2);
	SpritePtr sprite = sGameEngine->LoadSprite("Resources/test1.bmp");
	spriteRenderer->SetSprite(sprite);

	//mario
	obj = sGameEngine->CreateGameObject();
	obj->SetGlobalPosition(Vector(0, 170));
	obj->AddRigidBody2D();
	spriteRenderer = obj->AddSpriteRenderer();
	sprite = sGameEngine->LoadSprite("Resources/player0.png");
	sprite->SetDrawRect(Rect(16, 16));
	spriteRenderer->SetSprite(sprite);

	sCamera->AddBehavior(CameraControlPtr(new CameraControl(sCamera)));
}

void Game::Run() {

	sGameEngine->Run();
}