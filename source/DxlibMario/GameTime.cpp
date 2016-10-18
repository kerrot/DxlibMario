#include "GameTime.h"
#include "GameEngine.h"

GameTime::~GameTime() {

}

GameTime::GameTime() 
: _current(0)
, _pause(false) {
}

GameTimePtr GameTime::GetInstance() {
	return sGameEngine->GetGameTime();
}

void GameTime::UpdateTime() {
	_unpausedLast = _unpausedCurrent;
	_unpausedCurrent = UpdateCurrent();

	if (!_pause) {
		_last = _current;
		_current += UnPausedDeltaTime();
	}
}

void GameTime::Pause() {
	_pause = true;
}

void GameTime::Resume() {
	_pause = false;
}

__int64 GameTime::Current() {
	return _current;
}

__int64 GameTime::DeltaTime() {
	if (_pause) {
		return 0;
	}
	return _current - _last;
}

__int64 GameTime::UnPausedCurrent() {
	return _unpausedCurrent;
}

__int64 GameTime::UnPausedDeltaTime() {
	return _unpausedCurrent - _unpausedLast;
}
