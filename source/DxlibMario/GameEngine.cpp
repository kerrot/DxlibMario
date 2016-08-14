#include "GameEngine.h"

GameEngine* GameEngine::_instance;


GameEngine::GameEngine( ) {

}


GameEngine::~GameEngine( ) {
	delete _instance;
}


GameEngine* GameEngine::getInstance( ) {
	if ( !_instance ) {
		_instance = new GameEngine ( );
	}

	return _instance;
}