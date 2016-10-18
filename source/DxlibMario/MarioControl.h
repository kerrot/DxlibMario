#pragma once
#include "Behavior.h"

PTR( MarioControl )

class MarioControl : public Behavior
{
public:
	MarioControl();
	virtual ~MarioControl();

	virtual void Start();
	virtual void Update();

	virtual void CollisionEnter(GameObjectPtr other);

	bool _dead;
};

