#pragma once
#include "smart_ptr.h"

PTR (AnimationData)
PTR (GameObject)

class AnimationData {
public:
	virtual ~AnimationData() = 0;

	virtual void Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next) = 0;

	__int64 GetTime();
protected:
	AnimationData(__int64 time);

	__int64 _time;
};

