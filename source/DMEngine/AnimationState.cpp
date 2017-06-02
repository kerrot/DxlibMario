#include "AnimationState.h"

AnimationState::AnimationState(const char* name) 
: _name(name) {
}


AnimationState::~AnimationState() {
}

void AnimationState::SetClip(AnimationClipWPtr clip) {
	_clip = clip;
}

void AnimationState::Update(__int64 time, GameObjectPtr obj) {
	if (!_clip.expired()) {
		AnimationClipPtr tmp = _clip.lock();
		tmp->Update(time, obj);
	}
}

__int64 AnimationState::GetTime() {
	if (!_clip.expired()) {
		AnimationClipPtr tmp = _clip.lock();
		return tmp->GetTime();
	}
	
	return 1;
}
