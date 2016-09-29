#pragma once
#include "smart_ptr.h"

PTR( Component );

class Component {
public:
	virtual ~Component() = 0;
protected:
	Component() {}
};