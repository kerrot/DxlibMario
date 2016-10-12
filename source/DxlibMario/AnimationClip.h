#pragma once
#include "smart_ptr.h"
#include <map>
#include <string>

PTR(AnimationClip)
PTR(AnimationProperty)

enum AnimationPropertyType;

class AnimationClip {
	friend class GameEngine;
public:
	virtual ~AnimationClip();

	AnimationPropertyWPtr CreateProperty(AnimationPropertyType type);

	void Update(__int64 time);
	__int64 GetTime();

private:
	AnimationClip(const char* name);

	std::string _name;
	std::map<AnimationPropertyType, AnimationPropertyPtr> _properties;
};