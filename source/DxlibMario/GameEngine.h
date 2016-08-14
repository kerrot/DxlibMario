#pragma once

class GameEngine {
public:
	static GameEngine* getInstance( );
	~GameEngine( );
private:
	GameEngine( );
	static GameEngine* _instance;
};