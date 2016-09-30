#pragma once
#include "smart_ptr.h"

PTR( Component );
PTR( GameObject );

class Component : public std::enable_shared_from_this < Component > {
public:
	virtual ~Component() = 0;
	virtual void Render();

	bool IsEnabled() const;

	GameObjectPtr GetGameObject();
protected:
	Component(GameObjectPtr obj);

	GameObjectPtr _gameobject;

	bool _enabled;
};