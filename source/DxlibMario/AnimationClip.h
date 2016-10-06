#pragma once
#include "smart_ptr.h"
#include <map>

PTR( AnimationClip )
PTR( AnimationKey )

class AnimationClip {
public:
	AnimationClip();
	virtual ~AnimationClip();

	AnimationKeyPtr AddKey(float time);

	std::map<float, AnimationKeyPtr> _keys;
};

