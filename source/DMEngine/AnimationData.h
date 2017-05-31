#pragma once
#include "smart_ptr.h"

PTR (AnimationData)
PTR (GameObject)

// key frame
class AnimationData {
public:
	virtual ~AnimationData() = 0;

	// apply change to gameobject
	virtual void Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next) = 0;

	__int64 GetTime();
protected:
	AnimationData(__int64 time);

	__int64 _time;
};

