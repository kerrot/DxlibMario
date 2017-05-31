#pragma once
#include "smart_ptr.h"

PTR(GameTime);

//for time used in game
class GameTime {
public:
	virtual ~GameTime() = 0;

	static GameTimePtr GetInstance();

	//get current time
	void UpdateTime();
	
	// stop game time (not influence unpaused time)
	void Pause();
	// restart game time
	void Resume();

	__int64 Current();
	__int64 DeltaTime();

	__int64 UnPausedCurrent();
	__int64 UnPausedDeltaTime();

protected:
	GameTime();

	virtual __int64 UpdateCurrent() = 0;

protected:
	bool _pause; // is system pause

	__int64 _current;	//current frame's gametime from game start 
	__int64 _last;		//last frame's gametime from game start 

	__int64 _unpausedCurrent;	//current frame's realtime from game start 
	__int64 _unpausedLast;		//last frame's realtime from game start 
};

#define sGameTime GameTime::GetInstance()