#pragma once
#include "AnimationData.h"

PTR(AnimationDataEnable)
PTR(ObjectBase)

// change gameobject visiblity
class AnimationDataEnable : public AnimationData {
	friend class AnimationProperty;		//can only created by AnimationProperty
public:
	virtual ~AnimationDataEnable();

	virtual void Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next);

	void SetEnable(ObjectBaseWPtr obj, bool enable);
private:
	AnimationDataEnable(__int64 time);

	void Apply();

	bool _enable;
	ObjectBaseWPtr _obj;
};

