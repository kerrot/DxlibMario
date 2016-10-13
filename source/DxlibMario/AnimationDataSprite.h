#pragma once
#include "AnimationData.h"
#include "mathmatics.h"
#include "Common.h"

PTR(Sprite)
PTR(AnimationDataSprite)

class AnimationDataSprite : public AnimationData {
	friend class AnimationProperty;
public:
	virtual ~AnimationDataSprite();

	virtual void Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next);

	void SetSprite(SpritePtr sprite);
	SpritePtr GetSprite() const;

	const Rect& GetRect() const;
	void SetDrawRect(const Rect & rect);

	void SetPivot(int x, int y);
	void GetPivot(int& x, int& y);

private:
	AnimationDataSprite(__int64 time);

	SpritePtr _sprite;
	Rect _range;

	int _pivotX;
	int _pivotY;
};

