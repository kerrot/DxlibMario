#include "Animator.h"
#include "AnimationState.h"
#include "GameTime.h"

Animator::Animator()
: _animationSpeed(1) {
}


Animator::~Animator() {
}

AnimationStatePtr Animator::AddState(const char* name) {
	std::map<std::string, AnimationStatePtr>::iterator iter = _states.find(name);
	if (iter != _states.end()) {
		return iter->second;
	}

	AnimationStatePtr tmp = AnimationStatePtr(new AnimationState(name));
	_states[name] = tmp;

	if (!_currentState) {
		_currentState = tmp;
	}

	return tmp;
}

void Animator::Update() {
	if (!_currentState) {
		return;
	}

	_currentState->Update(_currentTime, _gameobject);

	_currentTime += (__int64)((double)sGameTime->DeltaTime() * _animationSpeed);

	__int64 clipTime = _currentState->GetTime();
	if (clipTime > 0) {
		_currentTime %= clipTime;
	}
}

void Animator::ChangeState(const char * name) {
	std::map<std::string, AnimationStatePtr>::iterator iter = _states.find(name);
	if (iter != _states.end() && iter->second != _currentState) {
		_currentState = iter->second;
		_currentTime = 0;
	}
}

void Animator::SetSpeed(double speed) {
	_animationSpeed = speed;
}