#pragma once
#include "smart_ptr.h"

PTR( AnimationProperty )

class AnimationProperty {
friend class AnimationClip;
public:
	virtual ~AnimationProperty();

private:
	AnimationProperty();
};

