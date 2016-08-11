#pragma once

class GameEngine {
public:
	static GameEngine* getInstance( );
	virtual ~GameEngine( );
private:
	GameEngine( );


	static GameEngine* _instance;
};

