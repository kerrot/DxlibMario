#pragma once
#include "ObjectBase.h"

PTR( Component );
PTR( GameObject );

class Component : public ObjectBase {
	friend class GameObject; // for Destroy
public:
	virtual ~Component() = 0;
	virtual void Render();

	GameObjectPtr GetGameObject();
protected:
	Component();

	virtual void OnDestroy();

	GameObjectPtr _gameobject; // the owner gameobject

	bool _enabled;

private:
	void Destroy();
};