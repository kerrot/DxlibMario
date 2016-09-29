#include "Game.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Renderer.h"

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

	GameObjectPtr obj = sGameEngine->CreateGameObject();
	SpriteRendererPtr sprite = obj->AddSpriteRenderer();
	sprite->SetSprite(sGameEngine->LoadSprite("Resources/test1.bmp"));
}

void Game::Run() {

	sGameEngine->Run();
}