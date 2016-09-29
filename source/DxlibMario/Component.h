#pragma once
#include "smart_ptr.h"

PTR( Component );
PTR( GameObject );

class Component {
public:
	virtual ~Component() = 0;
	virtual void Render() {}
protected:
	Component(GameObjectPtr obj) : _gameobject(obj) {}

	GameObjectPtr _gameobject;
};