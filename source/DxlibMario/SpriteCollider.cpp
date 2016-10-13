#include "SpriteCollider.h"
#include "SpriteRenderer.h"
#include "GameObjectHelper.h"

SpriteCollider::SpriteCollider()
: _traceSprite(true) {
}


SpriteCollider::~SpriteCollider() {
}

const Rect & SpriteCollider::GetRect() {
	if (_traceSprite) {
		SpriteRendererPtr renderer = GameObjectHelper::GetGameObjectComponent<SpriteRenderer>(_gameobject);
		if (renderer) {
			int x, y;
			renderer->GetPivot(x, y);

			_range._left = - x;
			_range._up = - y;
			_range._right = _range._left + renderer->GetRect()._right - renderer->GetRect()._left;
			_range._down = _range._up + renderer->GetRect()._down - renderer->GetRect()._up;

			return _range;
		}
	}

	return _range;
}

void SpriteCollider::EnableTrace() {
	_traceSprite = true;
}

void SpriteCollider::SetCustomRange(const Rect & rect) {
	_range = rect;
	_traceSprite = false;
}
