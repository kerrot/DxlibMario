#pragma once
#include "smart_ptr.h"

PTR (AnimationData)

class AnimationData {
public:
	virtual ~AnimationData() = 0;
protected:
	AnimationData();
};

