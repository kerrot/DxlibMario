#pragma once
#include "AnimationData.h"

PTR(AnimationDataEnable)
PTR(ObjectBase)

class AnimationDataEnable : public AnimationData {
	friend class AnimationProperty;
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

