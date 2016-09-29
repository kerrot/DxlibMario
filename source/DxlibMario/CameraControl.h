#pragma once
#include "Behavior.h"

PTR( CameraControl )

class CameraControl : public Behavior
{
public:
	CameraControl(GameObjectPtr obj);
	virtual ~CameraControl();

	virtual void Update();
};

