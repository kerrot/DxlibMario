#include "AnimationProperty.h"

__int64 AnimationProperty::KeyMaxTime() {
	if (_keys.empty()) {
		return 0;
	}

	return _keys.rbegin()->first;
}

AnimationProperty::AnimationProperty(AnimationPropertyType type)
: _type(type) {
}

AnimationProperty::~AnimationProperty() {
}


void AnimationProperty::Update(__int64 time) {
	if (_keys.empty()) {
		return;
	}

	AnimationDataPtr before, end;
	GetData(time, before, end);
}

void AnimationProperty::GetData(__int64 time, AnimationDataPtr & before, AnimationDataPtr & end) {


}

AnimationDataPtr AnimationProperty::AddKey(__int64 time) {
	std::map<__int64, AnimationDataPtr>::iterator iter = _keys.find(time);
	if (iter != _keys.end()) {
		return iter->second;
	}

	AnimationDataPtr tmp;// = AnimationDataPtr(new);
	_keys[time] = tmp;

	return tmp;
}
