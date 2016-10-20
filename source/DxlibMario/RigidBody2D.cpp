#include "RigidBody2D.h"
#include "GameObject.h"
#include "GameObjectHelper.h"
#include "SpriteCollider.h"
#include "GameEngine.h"
#include "GameTime.h"
#include <cmath>

RigidBody2D::RigidBody2D()
: _drag(0) {
	
}

RigidBody2D::~RigidBody2D() {
}

void RigidBody2D::ComputeCollision(int & finalx, int & finaly, GameObjectPtr other) {
	SpriteColliderPtr collider1 = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(_gameobject);
	SpriteColliderPtr collider2 = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(other);

	Rect rect1(collider1->GetRect()), rect2(collider2->GetRect());
	rect1.Shift((int)_gameobject->GetGlobalPosition().x, (int)_gameobject->GetGlobalPosition().y);
	rect2.Shift((int)other->GetGlobalPosition().x, (int)other->GetGlobalPosition().y);

	int tmpx = finalx, tmpy = finaly;
	ComputeFinalShift(tmpx, tmpy, rect1, rect2);

	if (abs(tmpx) < abs(finalx)) {
		finalx = tmpx;
	}
	if (abs(tmpy) < abs(finaly)) {
		finaly = tmpy;
	}
}

void RigidBody2D::ComputeFinalShift(int & x, int & y, Rect & rect1, Rect & rect2) {
	if (_velocity.x == 0) {
		ComputeSingleShift(y, rect1, rect2, _velocity);
	}
	else if (_velocity.y == 0) {
		ComputeSingleShift(x, rect1, rect2, _velocity);
	}
	else {
		bool xfirst = true;
		if (LineSegmentOverlap(rect1._left, rect1._right, rect2._left, rect2._right)) {
			xfirst = false;
		}
		else if (LineSegmentOverlap(rect1._up, rect1._down, rect2._up, rect2._down)) {
			xfirst = true;
		}
		else {

			double width = (_velocity.x > 0) ? rect2._left - rect1._right - 1 : rect1._left - rect2._right - 1;
			double height = (_velocity.y > 0) ? rect2._up - rect1._down - 1 : rect1._up - rect2._down - 1;

			if (width == 0) {
				xfirst = false;
			}
			else if (height == 0) {
				xfirst = true;
			}
			else {
				double rate = width / height;
				xfirst = (rate < _velocity.x / _velocity.y);
			}
		}

		if (xfirst) {
			ComputeSingleShift(x, rect1, rect2, Vector(_velocity.x, 0));
			ComputeSingleShift(y, rect1, rect2, Vector(0, _velocity.y));
		}
		else {
			ComputeSingleShift(y, rect1, rect2, Vector(0, _velocity.y));
			ComputeSingleShift(x, rect1, rect2, Vector(_velocity.x, 0));
		}
	}
}

void RigidBody2D::ComputeSingleShift(int& shift, Rect & rect1, Rect & rect2, const Vector& v) {
	Rect tmp(rect1);
	tmp.Shift((int)v.x, (int)v.y);

	if (Rect::IsCollision(tmp, rect2)) {
		if (v.x == 0) {
			shift = (v.y > 0) ? rect2._up - rect1._down - 1 : rect2._down - rect1._up + 1;
			rect1.Shift(0, shift);
		}
		else {
			shift = (v.x > 0) ? rect2._left - rect1._right - 1 : rect2._right - rect1._left + 1;
			rect1.Shift(shift, 0);
		}
	}
}

void RigidBody2D::Update() {
	_velocity += (_acceleration + _gravity) ;
	_acceleration = Vector();

	_velocity = _velocity.normalize() * (_velocity.getLength() - _drag);

	int finalx, tmpx, finaly, tmpy;
	finalx = tmpx = (int)_velocity.x;
	finaly = tmpy = (int)_velocity.y;
	if (finalx != 0 || finaly != 0) {
		std::list<GameObjectPtr> hits;

		const std::map<int, GameObjectPtr>& objs = sGameEngine->GetGameObjects();
		for (std::map<int, GameObjectPtr>::const_iterator iter = objs.begin();
			iter != objs.end(); ++iter) {

			if (SpriteCollider::CollideWith(_gameobject, iter->second, _velocity)) {
				hits.push_back(iter->second);

				ComputeCollision(finalx, finaly, iter->second);
			}
		}

		if (finalx != tmpx) {
			_velocity.x = 0;
		}
		if (finaly != tmpy) {
			_velocity.y = 0;
		}

		_gameobject->Translate(Vector(finalx, finaly));

		for (std::list<GameObjectPtr>::iterator iter = hits.begin();
			iter != hits.end(); ++iter) {
			GameObjectCollision(_gameobject, *iter);
			GameObjectCollision(*iter, _gameobject);
		}
	}
}

void RigidBody2D::SetGravity(const Vector & g) {
	_gravity = g;
}

const Vector & RigidBody2D::GetGravity() {
	return _gravity;
}

void RigidBody2D::AddAcceleration(const Vector & a) {
	_acceleration += a;
}

void RigidBody2D::SetAcceleration(const Vector & a) {
	_acceleration = a;
}

const Vector & RigidBody2D::GetAcceleration() {
	return _acceleration;
}

void RigidBody2D::AddVelocity(const Vector & v) {
	_velocity += v;
}

void RigidBody2D::SetVelocity(const Vector & v) {
	_velocity = v;
}

const Vector & RigidBody2D::GetVelocity() {
	return _velocity;
}

void RigidBody2D::SetDrag(double drag) {
	_drag = drag;
}