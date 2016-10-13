#pragma once
#include "Behavior.h"

PTR( BlockControl )

class BlockControl : public Behavior {
public:
	BlockControl();
	virtual ~BlockControl();

	virtual void Start();
	virtual void Update();

	virtual void CollisionEnter(GameObjectPtr other);
};

