#pragma once
#include "Behavior.h"

PTR( MarioControl )

class MarioControl : public Behavior
{
public:
	MarioControl(GameObjectPtr obj);
	virtual ~MarioControl();

	virtual void Update();
};

