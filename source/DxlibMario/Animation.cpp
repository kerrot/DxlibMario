#include "Animation.h"
#include "GameTime.h"
#include "AnimationClip.h"

Animation::Animation()
: _current(0)
, _pause(true) {
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

	_current += sGameTime->DeltaTime();

	if (clipTime > 0) {
		_current %= clipTime;
	}
}
