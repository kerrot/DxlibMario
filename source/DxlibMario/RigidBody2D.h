#pragma once
#include "Component.h"
#include "mathmatics.h"

PTR( RigidBody2D )

class RigidBody2D : public Component {
friend class GameObject;
public:
	virtual ~RigidBody2D();

	void Update();
	void SetGravity(const Vector& g);

private:
	RigidBody2D(GameObjectPtr obj);

	int _drag;

	Vector _gravity;
	Vector _velocity;
	Vector _acceleration;
};

