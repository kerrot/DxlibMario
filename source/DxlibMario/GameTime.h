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

	__int64 _current;	//gametime of current frame
	__int64 _last;		//gametime of last frame

	__int64 _unpausedCurrent;	//realtime of current frame from game start 
	__int64 _unpausedLast;		//realtime of last frame from game start 
};

#define sGameTime GameTime::GetInstance()