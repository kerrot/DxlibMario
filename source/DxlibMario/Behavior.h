#pragma once
#include "smart_ptr.h"
#include "Component.h"

PTR( Behavior );
PTR( GameObject );

class Behavior : public Component {
	friend class GameObject;
public:
	virtual ~Behavior() = 0;

	virtual void Start();
	virtual void Update();
	virtual void LastUpdate();
	
	void DestroyObject(GameObjectPtr obj);

	virtual void CollisionEnter(GameObjectPtr other);
	virtual void CollisionStay(GameObjectPtr other);
	virtual void CollisionExit(GameObjectPtr other);

protected:
	void InitBehavior();

	Behavior();

	bool _init;
};