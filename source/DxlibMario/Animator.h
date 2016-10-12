#pragma once
#include "Component.h"
#include <map>
#include <string>

PTR( Animator )
PTR( AnimationState )
PTR( GameObject )

class Animator: public Component {
friend class GameObject;
public:
	virtual ~Animator();

	AnimationStateWeakPtr AddState(const char* name);

private:
	Animator();

	std::map<std::string, AnimationStatePtr> _state;
};

