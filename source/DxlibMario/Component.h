#pragma once
#include "smart_ptr.h"

PTR( Component );
PTR( GameObject );

class Component {
public:
	virtual ~Component() = 0;
	virtual void Render();

	bool IsEnabled() const;
protected:
	Component(GameObjectPtr obj);

	GameObjectPtr _gameobject;

	bool _enabled;
};