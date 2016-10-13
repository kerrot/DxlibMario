#pragma once
#include "AnimationData.h"
#include "mathmatics.h"

PTR(AnimationDataPosition)

class AnimationDataPosition : public AnimationData {
	friend class AnimationProperty;
public:
	virtual ~AnimationDataPosition();

	virtual void Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next);

	void SetPosition(const Vector& pos);
	const Vector& GetPosition() const;

private:
	AnimationDataPosition(__int64 time);

	bool _local;
	Vector _position;
};

