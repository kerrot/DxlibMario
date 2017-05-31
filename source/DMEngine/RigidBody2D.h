#pragma once
#include "Component.h"
#include "mathmatics.h"

struct Rect;

PTR( RigidBody2D )
PTR( GameObject )

class RigidBody2D : public Component {
	friend class GameObject; // only gameobject can create this component
public:
	virtual ~RigidBody2D();

	void Update();
	
	void SetGravity(const Vector& g);
	const Vector& GetGravity();

	void AddAcceleration(const Vector& a);
	void SetAcceleration(const Vector& a);
	const Vector& GetAcceleration();

	void AddVelocity(const Vector& v);
	void SetVelocity(const Vector& v);
	const Vector& GetVelocity();

	void SetDrag(double drag);

private:
	RigidBody2D();

	void ComputeCollision(int & finalx, int & finaly, GameObjectPtr other); //compute final position when collision
	void ComputeFinalShift(int & x, int & y, Rect & rect1, Rect & rect2); // determine which direction first
	void ComputeSingleShift(int& shift, Rect & rect1, Rect & rect2, const Vector& v); //do the compute 

	double _drag; //resistance force

	Vector _gravity;
	Vector _velocity;
	Vector _acceleration;
};

