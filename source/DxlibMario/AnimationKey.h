#pragma once
#include "smart_ptr.h"

PTR(AnimationKey)

class AnimationKey {
friend class AnimationClip;
public:
	virtual ~AnimationKey();
private:
	AnimationKey();
};

