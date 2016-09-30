#include "RigidBody2D.h"
#include "GameObject.h"

RigidBody2D::RigidBody2D(GameObjectPtr obj)
: Component(obj)
, _drag(0) {

}


RigidBody2D::~RigidBody2D() {
}

void RigidBody2D::Update() {
	_velocity += _acceleration + _gravity;

	int speed = _velocity.getLength() - _drag;
	_velocity = _velocity.normalize() * speed;

	_gameobject->SetGlobalPosition(_gameobject->GetGlobalPosition() + _velocity);
}

void RigidBody2D::SetGravity(const Vector & g) {
	_gravity = g;
}
