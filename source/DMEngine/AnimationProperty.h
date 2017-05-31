#pragma once
#include "smart_ptr.h"
#include <map>
#include <vector>

PTR(AnimationProperty)
PTR(AnimationData)
PTR(GameObject)

enum AnimationPropertyType {
	ANIMATION_PROPERTY_POSITION,	//change game object position
	ANIMATION_PROPERTY_SPRITE,		//change sprite image
	ANIMATION_PROPERTY_ENABLE,		//change visiblity
};

// hold one type of Property and its key frames
class AnimationProperty {
	friend class AnimationClip; // only AnimationClip can create this
public:
	virtual ~AnimationProperty();

	void Update(__int64 time, GameObjectPtr ptr);
	AnimationDataPtr AddKey(__int64 time);
	// generate key by certain period
	std::vector<AnimationDataPtr> AddPeroidKeys(__int64 period, int num);

	__int64 KeyMaxTime();

private:
	AnimationProperty(AnimationPropertyType type);
	
	// get animation data with certain time
	void GetData(__int64 time, AnimationDataPtr& before, AnimationDataPtr& after);

private:
	AnimationPropertyType _type;
	std::map<__int64, AnimationDataPtr> _keys;
};