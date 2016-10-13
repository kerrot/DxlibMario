#pragma once
#include "smart_ptr.h"
#include <map>
#include <string>

PTR(AnimationClip)
PTR(AnimationProperty)
PTR(GameObject)

enum AnimationPropertyType;

class AnimationClip {
	friend class GameEngine;
public:
	virtual ~AnimationClip();

	AnimationPropertyPtr CreateProperty(AnimationPropertyType type);

	void Update(__int64 time, GameObjectPtr ptr);
	__int64 GetTime();

private:
	AnimationClip(const char* name);

	std::string _name;
	std::map<AnimationPropertyType, AnimationPropertyPtr> _properties;
};