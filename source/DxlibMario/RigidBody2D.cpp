#include "RigidBody2D.h"
#include "GameObject.h"
#include "GameObjectHelper.h"
#include "SpriteCollider.h"
#include "GameEngine.h"

RigidBody2D::RigidBody2D(GameObjectPtr obj)
: Component(obj)
, _drag(0) {

}

RigidBody2D::~RigidBody2D() {
}

bool RigidBody2D::CheckCollision(int & x, int & y) {
	bool result = false;

	SpriteColliderPtr collider = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(_gameobject);
	if (collider) {
		Vector pos = _gameobject->GetGlobalPosition() + _velocity;
		Rect rect(collider->GetRect());
		x = (int)pos.x;
		y = (int)pos.y;

		const std::map<int, GameObjectPtr>& objs = sGameEngine->GetGameObjects();
		for (std::map<int, GameObjectPtr>::const_iterator iter = objs.begin();
			iter != objs.end(); ++iter) {

			SpriteColliderPtr tmp = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(iter->second);
			if (_gameobject == iter->second || !tmp) {
				continue;
			}

			Rect rect1(rect), rect2(tmp->GetRect());
			rect1.Shift((int)pos.x, (int)pos.y);
			rect2.Shift((int)iter->second->GetGlobalPosition().x, (int)iter->second->GetGlobalPosition().y);

			if (Rect::IsCollision(rect1, rect2)) {
				result = true;

				ComputeFinalPosition(x, y, rect, rect2);
			}
		}
	}

	return result;
}

void RigidBody2D::ComputeFinalPosition(int & x, int & y, const Rect & rect1, const Rect & rect2) {
	
	if (_velocity.x != 0)
	{
		Rect tmpRect(rect1);
		tmpRect.Shift((int)_gameobject->GetGlobalPosition().x + (int)_velocity.x, (int)_gameobject->GetGlobalPosition().y);
		if (Rect::IsCollision(tmpRect, rect2)) {
			if (_velocity.x > 0) {
				int tmp = rect2._left - 1 - rect1._right;
				if (x > tmp) {
					x = tmp;
				}
			}
			else {
				int tmp = rect2._right + 1 - rect1._left;
				if (x < tmp) {
					x = tmp;
				}
			}
		}
	}
	
	if (_velocity.y != 0)
	{
		Rect tmpRect(rect1);
		tmpRect.Shift((int)_gameobject->GetGlobalPosition().x, (int)_gameobject->GetGlobalPosition().y + (int)_velocity.y);
		if (Rect::IsCollision(tmpRect, rect2)) {
			if (_velocity.y > 0) {
				int tmp = rect2._up - 1 - rect1._down;
				if (y > tmp) {
					y = tmp;
				}
			}
			else {
				int tmp = rect2._down + 1 - rect1._up;
				if (y < tmp) {
					y = tmp;
				}
			}
		}

	}
}

void RigidBody2D::Update() {
	_velocity += _acceleration + _gravity;

	_velocity = _velocity.normalize() * (_velocity.getLength() - _drag);

	int x, y;
	if (CheckCollision(x, y)) {
		if (x != _gameobject->GetGlobalPosition().x + _velocity.x) {
			_velocity.x = 0;
		}

		if (y != _gameobject->GetGlobalPosition().y + _velocity.y) {
			_velocity.y = 0;
		}

		_gameobject->SetGlobalPosition(Vector(x, y));
	}
	else {
		_gameobject->SetGlobalPosition(_gameobject->GetGlobalPosition() + _velocity);
	}

	_acceleration = Vector();
}

void RigidBody2D::SetGravity(const Vector & g) {
	_gravity = g;
}

const Vector & RigidBody2D::GetGravity() {
	return _gravity;
}

void RigidBody2D::SetAcceleration(const Vector & a) {
	_acceleration = a;
}

const Vector & RigidBody2D::GetAcceleration() {
	return _acceleration;
}

void RigidBody2D::SetVelocity(const Vector & v) {
	_velocity = v;
}

const Vector & RigidBody2D::GetVelocity() {
	return _velocity;
}

