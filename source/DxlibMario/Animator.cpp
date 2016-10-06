#include "Animator.h"
#include "AnimationState.h"


Animator::Animator(GameObjectPtr obj) 
: Component(obj) {
}


Animator::~Animator() {
}

AnimationStatePtr Animator::AddState(const char* name) {
	std::map<std::string, AnimationStatePtr>::iterator iter = _state.find(name);
	if (iter != _state.end()) {
		return iter->second;
	}

	AnimationStatePtr tmp = AnimationStatePtr(new AnimationState(name));
	_state[name] = tmp;

	return tmp;
}
