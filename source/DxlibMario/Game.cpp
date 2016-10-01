#include "Game.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "Renderer.h"
#include "Camera.h"
#include "CameraControl.h"
#include "RigidBody2D.h"
#include "SpriteCollider.h"

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
	RigidBody2DPtr rigid = obj->AddRigidBody2D();
	rigid->SetGravity(Vector(0, 1));
	obj->AddSpriteCollider();

	spriteRenderer = obj->AddSpriteRenderer();
	sprite = sGameEngine->LoadSprite("Resources/player0.png");
	spriteRenderer->SetSprite(sprite);
	spriteRenderer->SetDrawRect(Rect(16, 16));
	spriteRenderer->SetPivot(8, 16);

	//ground
	obj = sGameEngine->CreateGameObject();
	obj->SetGlobalPosition(Vector(0, 300));
	spriteRenderer = obj->AddSpriteRenderer();
	sprite = sGameEngine->LoadSprite("Resources/map.png");
	spriteRenderer->SetSprite(sprite);
	spriteRenderer->SetDrawRect(Rect(48, 64, 64, 80));
	obj->AddSpriteCollider();

	//camerawork
	sCamera->AddBehavior(CameraControlPtr(new CameraControl(sCamera)));
}

void Game::Run() {

	sGameEngine->Run();
}