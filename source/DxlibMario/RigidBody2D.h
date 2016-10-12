#pragma once
#include "Component.h"
#include "mathmatics.h"

struct Rect;

PTR( RigidBody2D )

class RigidBody2D : public Component {
friend class GameObject;
public:
	virtual ~RigidBody2D();

	void Update();
	
	void SetGravity(const Vector& g);
	const Vector& GetGravity();

	void SetAcceleration(const Vector& a);
	const Vector& GetAcceleration();

	void SetVelocity(const Vector& v);
	const Vector& GetVelocity();

private:
	RigidBody2D();

	bool CheckCollision(int & x, int & y);
	void ComputeFinalPosition(int &x, int&y, const Rect& rect1, const Rect& rect2);

	double _drag;

	Vector _gravity;
	Vector _velocity;
	Vector _acceleration;
};

