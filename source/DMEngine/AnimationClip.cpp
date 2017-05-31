#include "AnimationClip.h"
#include "AnimationProperty.h"

AnimationClip::AnimationClip(const char* name)
: _name(name) {
}


AnimationClip::~AnimationClip() {
}

AnimationPropertyPtr AnimationClip::CreateProperty(AnimationPropertyType type) {
	std::map<AnimationPropertyType, AnimationPropertyPtr>::iterator iter = _properties.find(type);
	if (iter != _properties.end())
	{
		return iter->second;
	}

	AnimationPropertyPtr tmp = AnimationPropertyPtr(new AnimationProperty(type));
	_properties[type] = tmp;

	return tmp;
}

void AnimationClip::Update(__int64 time, GameObjectPtr ptr) {
	for (std::map<AnimationPropertyType, AnimationPropertyPtr>::iterator iter = _properties.begin();
		iter != _properties.end(); ++iter) {
		iter->second->Update(time, ptr);
	}
}

__int64 AnimationClip::GetTime() {
	__int64 time = 1;
	for (std::map<AnimationPropertyType, AnimationPropertyPtr>::iterator iter = _properties.begin();
		iter != _properties.end(); ++iter) {
		__int64 tmp = iter->second->KeyMaxTime();
		if (tmp > time) {
			time = tmp;
		}
	}

	return time;
}
