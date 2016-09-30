#pragma once
#include "Component.h"
#include "mathmatics.h"

PTR( RigidBody2D )

class RigidBody2D : public Component {
friend class GameObject;
public:
	virtual ~RigidBody2D();

	void Update();
private:
	RigidBody2D(GameObjectPtr obj);

	Vector _gravity;
	Vector _velocity;
	Vector _acceleration;
};

