#pragma once
#include "smart_ptr.h"

PTR(GameTime);

class GameTime {
public:
	virtual ~GameTime() = 0;

	static GameTimePtr GetInstance();

	void UpdateTime();
	
	void Pause();
	void Resume();

	__int64 Current();
	__int64 DeltaTime();

	__int64 UnPausedCurrent();
	__int64 UnPausedDeltaTime();

protected:
	GameTime();

	virtual long UpdateCurrent() = 0;

	bool _pause;

	__int64 _current;
	__int64 _last;

	__int64 _unpausedCurrent;
	__int64 _unpausedLast;
};

#define sGameTime GameTime::GetInstance()