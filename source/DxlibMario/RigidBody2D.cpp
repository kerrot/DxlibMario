#include "RigidBody2D.h"
#include "GameObject.h"

RigidBody2D::RigidBody2D(GameObjectPtr obj)
: Component(obj)
, _gravity(Vector(0, 1)){

}


RigidBody2D::~RigidBody2D() {
}

void RigidBody2D::Update() {
	_velocity += _acceleration + _gravity;

	_gameobject->SetGlobalPosition(_gameobject->GetGlobalPosition() + _velocity);
}
