#include "AnimationDataSprite.h"
#include "GameObjectHelper.h"
#include "SpriteRenderer.h"
#include "Sprite.h"

AnimationDataSprite::AnimationDataSprite(__int64 time)
: AnimationData(time) 
, _pivotX(0)
, _pivotY(0) {
}


AnimationDataSprite::~AnimationDataSprite() {
}

void AnimationDataSprite::Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next) {
	if (!ptr) {
		return;
	}

	SpriteRendererPtr renderer = GameObjectHelper::GetGameObjectComponent<SpriteRenderer>(ptr);
	if (!renderer) {
		return;
	}

	AnimationDataSpritePtr data = std::dynamic_pointer_cast<AnimationDataSprite>(next);
	if (!data) {
		return;
	}

	if (time >  next->GetTime()) {
		renderer->SetSprite(data->GetSprite());
		renderer->SetDrawRect(data->GetRect());
	}
	else {
		renderer->SetSprite(_sprite);
		renderer->SetDrawRect(_range);
	}
}

void AnimationDataSprite::SetSprite(SpritePtr sprite) {
	_sprite = sprite;

	_range._right = _sprite->GetWidth();
	_range._down = _sprite->GetHeight();
}

SpritePtr AnimationDataSprite::GetSprite() const {
	return _sprite;
}

const Rect & AnimationDataSprite::GetRect() const {
	return _range;
}

void AnimationDataSprite::SetDrawRect(const Rect & rect) {
	_range = rect;
}

void AnimationDataSprite::SetPivot(int x, int y) {
	_pivotX = x;
	_pivotY = y;
}

void AnimationDataSprite::GetPivot(int & x, int & y) {
	x = _pivotX;
	y = _pivotY;
}