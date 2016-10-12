#include "Animator.h"
#include "AnimationState.h"


Animator::Animator() {
}


Animator::~Animator() {
}

AnimationStateWPtr Animator::AddState(const char* name) {
	std::map<std::string, AnimationStatePtr>::iterator iter = _state.find(name);
	if (iter != _state.end()) {
		return iter->second;
	}

	AnimationStatePtr tmp = AnimationStatePtr(new AnimationState(name));
	_state[name] = tmp;

	return tmp;
}
