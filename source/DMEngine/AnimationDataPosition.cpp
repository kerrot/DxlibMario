#include "AnimationDataPosition.h"
#include "GameObject.h"

AnimationDataPosition::~AnimationDataPosition(){
}

AnimationDataPosition::AnimationDataPosition(__int64 time) 
: AnimationData(time) 
, _local(false) {
}

void AnimationDataPosition::Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next) {
	if (!ptr) {
		return;
	}
	
	AnimationDataPositionPtr data = std::dynamic_pointer_cast<AnimationDataPosition>(next);
	if (!data) {
		return;
	}

	Vector answer;

	if (time >  next->GetTime()) {
		answer = data->GetPosition();
	}
	else if (_time == next->GetTime()) {
		answer = _position;
	}
	else {
		double rate = (double)(time - _time) / (double)(next->GetTime() - _time);

		answer = (data->GetPosition() - _position) * rate + _position;
	}

	(_local) ? ptr->SetlocalPosition(answer) : ptr->SetGlobalPosition(answer);
}

void AnimationDataPosition::SetPosition(const Vector & pos) {
	_position = pos;
}

const Vector & AnimationDataPosition::GetPosition() const {
	return _position;
}
