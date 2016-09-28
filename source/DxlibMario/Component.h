#pragma once
#include "smart_ptr.h"

PTR( Component );

class Component {
	friend class GameEngine;
public:
	virtual ~Component() = 0;
protected:
	Component() {}
};