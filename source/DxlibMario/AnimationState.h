#pragma once
#include "smart_ptr.h"
#include <string>

PTR( AnimationState )
PTR( AnimationClip )

class AnimationState {
friend class Animator;
public:
	virtual ~AnimationState();

	void SetClip(AnimationClipPtr clip);

private:
	AnimationState(const char* name);

	std::string _name;
	AnimationClipPtr _clip;
};

