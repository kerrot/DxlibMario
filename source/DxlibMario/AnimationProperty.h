#pragma once
#include "smart_ptr.h"
#include <map>
#include <vector>

PTR(AnimationProperty)
PTR(AnimationData)
PTR(GameObject)

enum AnimationPropertyType {
	ANIMATION_PROPERTY_POSITION,
	ANIMATION_PROPERTY_SPRITE,
};

class AnimationProperty {
	friend class AnimationClip;
public:
	virtual ~AnimationProperty();

	void Update(__int64 time, GameObjectPtr ptr);
	AnimationDataPtr AddKey(__int64 time);

	std::vector<AnimationDataPtr> AddPeroidKeys(__int64 period, int num);

	__int64 KeyMaxTime();

private:
	AnimationProperty(AnimationPropertyType type);
	std::map<__int64, AnimationDataPtr> _keys;

	void GetData(__int64 time, AnimationDataPtr& before, AnimationDataPtr& end);

	AnimationPropertyType _type;
};