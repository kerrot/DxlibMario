#pragma once
#include "Behavior.h"

PTR(GoombaControl)

class GoombaControl : public Behavior {
public:
	GoombaControl();
	virtual ~GoombaControl();

	virtual void Start();
};

