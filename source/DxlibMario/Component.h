#pragma once
#include "smart_ptr.h"

PTR( Component );
PTR( GameObject );

class Component : public std::enable_shared_from_this < Component > {
	friend class GameObject;
public:
	virtual ~Component() = 0;
	virtual void Render();

	bool IsEnabled() const;

	GameObjectPtr GetGameObject();
protected:
	Component();

	virtual void OnDestroy();

	GameObjectPtr _gameobject;

	bool _enabled;

private:
	void Destroy();
};