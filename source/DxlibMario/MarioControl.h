#pragma once
#include "Behavior.h"

PTR( MarioControl )

class MarioControl : public Behavior
{
public:
	MarioControl();
	virtual ~MarioControl();

	virtual void Update();
};

