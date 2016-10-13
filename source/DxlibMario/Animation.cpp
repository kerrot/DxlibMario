#include "Animation.h"
#include "GameTime.h"
#include "AnimationClip.h"

Animation::Animation()
: _current(0)
, _clipTime(0) 
, _pause(true) {
}


Animation::~Animation() {
}

void Animation::SetClip(AnimationClipWPtr ptr) {
	_clip = ptr;

	if (!_clip.expired()) {
		AnimationClipPtr tmp = _clip.lock();
		_clipTime = tmp->GetTime();
	}
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

	if (!_clip.expired()) {
		AnimationClipPtr tmp = _clip.lock();
		tmp->Update(_current, _gameobject);
	}

	_current += sGameTime->DeltaTime();

	if (_clipTime > 0) {
		_current %= _clipTime;
	}
}
