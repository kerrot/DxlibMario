#include "Game.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "Renderer.h"
#include "Camera.h"
#include "RigidBody2D.h"
#include "SpriteCollider.h"
#include "CameraControl.h"
#include "MarioControl.h"
#include "BlockControl.h"
#include "GoombaControl.h"

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
	obj->AddBehavior(MarioControlPtr (new MarioControl()));
	obj->SetGlobalPosition(Vector(70, 170));
	RigidBody2DPtr rigid = obj->AddRigidBody2D();
	rigid->SetGravity(Vector(0, 1));
	rigid->SetDrag(0.5);
	obj->AddSpriteCollider();

	spriteRenderer = obj->AddSpriteRenderer();
	sprite = sGameEngine->LoadSprite("Resources/player0.png");
	spriteRenderer->SetSprite(sprite);
	spriteRenderer->SetRect(Rect(16, 16));
	spriteRenderer->SetPivot(8, 16);


	//ground
	for (int i = 0; i < 20; ++i)
	{
		obj = sGameEngine->CreateGameObject();
		obj->SetGlobalPosition(Vector(i * 16, 300));
		spriteRenderer = obj->AddSpriteRenderer();
		sprite = sGameEngine->LoadSprite("Resources/map.png");
		spriteRenderer->SetSprite(sprite);
		spriteRenderer->SetRect(Rect(48, 64, 64, 80));
		obj->AddSpriteCollider();
	}

	//block
	obj = sGameEngine->CreateGameObject();
	obj->SetGlobalPosition(Vector(100, 250));
	spriteRenderer = obj->AddSpriteRenderer();
	sprite = sGameEngine->LoadSprite("Resources/map.png");
	spriteRenderer->SetSprite(sprite);
	spriteRenderer->SetRect(Rect(80, 96, 16, 32));
	obj->AddSpriteCollider();
	obj->AddBehavior(BlockControlPtr(new BlockControl));

	//enermy
	obj = sGameEngine->CreateGameObject();
	obj->SetGlobalPosition(Vector(200, 250));
	spriteRenderer = obj->AddSpriteRenderer();
	rigid = obj->AddRigidBody2D();
	rigid->SetGravity(Vector(0, 1));
	obj->AddSpriteCollider();
	obj->AddBehavior(GoombaControlPtr(new GoombaControl));


	//camerawork
	sCamera->AddBehavior(CameraControlPtr(new CameraControl()));
}

void Game::Run() {

	sGameEngine->Run();
}