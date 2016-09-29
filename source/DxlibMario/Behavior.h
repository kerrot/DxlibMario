#pragma once
#include "smart_ptr.h"
#include "Component.h"

PTR( Behavior );

class Behavior : public Component {
public:
	virtual ~Behavior() = 0;

	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void LastUpdate();
	
protected:
	Behavior(GameObjectPtr obj);
};