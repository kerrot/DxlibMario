#include "AnimationClip.h"
#include "AnimationKey.h"

AnimationClip::AnimationClip() {
}


AnimationClip::~AnimationClip() {
}

AnimationKeyPtr AnimationClip::AddKey(float time) {
	if (time >= 0) {
		std::map<float, AnimationKeyPtr>::iterator iter = _keys.find(time);
		if (iter != _keys.end()) {
			return iter->second;
		}

		AnimationKeyPtr tmp = AnimationKeyPtr(new AnimationKey);
		_keys[time] = tmp;

		return tmp;
	}

	return 0;
}