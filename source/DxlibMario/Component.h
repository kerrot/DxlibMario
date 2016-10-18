#pragma once
#include "ObjectBase.h"

PTR( Component );
PTR( GameObject );

class Component : public ObjectBase {
	friend class GameObject;
public:
	virtual ~Component() = 0;
	virtual void Render();

	GameObjectPtr GetGameObject();
protected:
	Component();

	virtual void OnDestroy();

	GameObjectPtr _gameobject;

	bool _enabled;

private:
	void Destroy();
};