#include "Animation.h"
#include "GameTime.h"
#include "AnimationClip.h"

Animation::Animation()
: _current(0)
, _pause(true)
, _unscaledTime(false)
, _animationSpeed(1) {
}


Animation::~Animation() {
}

void Animation::SetClip(AnimationClipWPtr ptr) {
	_clip = ptr;
}

void Animation::Play() {
	_pause = false;
}

void Animation::Stop() {
	_pause = true;
	_current = 0;
}

void Animation::Pause() {
	_pause = true;
}

void Animation::Update() {
	if (_pause) {
		return;
	}

	__int64 clipTime = 1;

	if (!_clip.expired()) {
		AnimationClipPtr tmp = _clip.lock();
		tmp->Update(_current, _gameobject);
		clipTime = tmp->GetTime();
	}

	_current += (double)((_unscaledTime) ? sGameTime->UnPausedDeltaTime() : sGameTime->DeltaTime()) * _animationSpeed;

	if (clipTime > 0) {
		_current %= clipTime;
	}
}

void Animation::SetSpeed(double speed) {
	_animationSpeed = speed;
}

void Animation::SetUnscaled(bool v) {
	_unscaledTime = v;
}