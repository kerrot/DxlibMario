#pragma once
#include "smart_ptr.h"
#include <map>
#include <string>

PTR( AnimationClip )


class AnimationClip {
friend class GameEngine;
public:
	virtual ~AnimationClip();
private:
	AnimationClip(const char* name);

	std::string _name;
};

