#pragma once
#include "AnimationData.h"
#include "mathmatics.h"
#include "Common.h"
#include <vector>

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

	static void SetSpriteAnimation(std::vector<AnimationDataPtr>& data, SpritePtr sprite, int sizex, int sizey, int startx, int starty, int pivotx, int pivoty);

private:
	AnimationDataSprite(__int64 time);

	SpritePtr _sprite;
	Rect _range;

	int _pivotX;
	int _pivotY;
};

