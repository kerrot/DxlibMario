#pragma once
#include "Behavior.h"

PTR( BlockControl )

class BlockControl : public Behavior {
public:
	BlockControl();
	virtual ~BlockControl();

	virtual void CollisionEnter(GameObjectPtr other);
};

