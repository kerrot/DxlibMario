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

bool SpriteCollider::CollideWith(GameObjectPtr obj, GameObjectPtr other, const Vector& velocity) {
	if (!obj || !other || obj == other || !obj->IsEnabled() || !other->IsEnabled()) {
		return false;
	}

	SpriteColliderPtr collider1 = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(obj);
	SpriteColliderPtr collider2 = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(other);
	if (!collider1 || !collider1->IsEnabled() || !collider2 || !collider2->IsEnabled()) {
		return false;
	}

	Rect rect1(collider1->GetRect()), rect2(collider2->GetRect());
	rect2.Shift((int)other->GetGlobalPosition().x, (int)other->GetGlobalPosition().y);
	
	int width = rect2._right - rect2._left + rect1._right - rect1._left;
	int height = rect2._down - rect2._up + rect1._down - rect1._up;
	int minLength = (width > height) ? height : width;

	double oriLength = velocity.getLength();
	if (oriLength > minLength) {
		Vector normalized = velocity.normalize();

		double stepLength = minLength;
		while (stepLength < oriLength) {
			
			Vector tmpLength = normalized * stepLength;
			rect1 = collider1->GetRect();
			rect1.Shift((int)(obj->GetGlobalPosition().x + tmpLength.x) , (int)(obj->GetGlobalPosition().y + tmpLength.y));
			if (Rect::IsCollision(rect1, rect2)) {
				return true;
			}

			stepLength += minLength;
		}
	}
	
	rect1 = collider1->GetRect();
	rect1.Shift((int)(obj->GetGlobalPosition().x + velocity.x), (int)(obj->GetGlobalPosition().y + velocity.y));
	return Rect::IsCollision(rect1, rect2);
}

void SpriteCollider::SetCustomRange(const Rect & rect) {
	_range = rect;
	_traceSprite = false;
}
