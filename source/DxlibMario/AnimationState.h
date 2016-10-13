#pragma once
#include "smart_ptr.h"
#include <string>

PTR( AnimationState )
PTR( AnimationClip )
PTR( GameObject )

class AnimationState {
friend class Animator;
public:
	virtual ~AnimationState();

	void SetClip(AnimationClipWPtr clip);

	void Update(__int64 time, GameObjectPtr obj);

	__int64 GetTime();

private:
	AnimationState(const char* name);

	std::string _name;
	AnimationClipWPtr _clip;
};

