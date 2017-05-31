#pragma once
#include "AnimationData.h"
#include "mathmatics.h"
#include "Common.h"
#include <vector>

PTR(Sprite)
PTR(AnimationDataSprite)

// change gameobject sprite and setting
class AnimationDataSprite : public AnimationData {
	friend class AnimationProperty;	//can only created by AnimationProperty
public:
	virtual ~AnimationDataSprite();

	virtual void Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next);

	void SetSprite(SpritePtr sprite);
	SpritePtr GetSprite() const;

	const Rect& GetRect() const;
	void SetDrawRect(const Rect & rect);

	void SetPivot(int x, int y);
	void GetPivot(int& x, int& y);

	// automatically generate key frame with continuous sprite animation
	// sizex, sizey - size of every block
	// startx, starty - start position to generate
	// pivotx, pivoty - pivot of the gernerated sprite
	static void SetSpriteAnimation(std::vector<AnimationDataPtr>& data, SpritePtr sprite, int sizex, int sizey, int startx, int starty, int pivotx, int pivoty);

private:
	AnimationDataSprite(__int64 time);

	SpritePtr _sprite;
	Rect _range;

	int _pivotX;
	int _pivotY;
};

