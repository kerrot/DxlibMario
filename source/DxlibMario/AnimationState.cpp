#include "AnimationState.h"


AnimationState::AnimationState(const char* name) 
: _name(name) {
}


AnimationState::~AnimationState() {
}

void AnimationState::SetClip(AnimationClipPtr clip) {
	_clip = clip;
}
