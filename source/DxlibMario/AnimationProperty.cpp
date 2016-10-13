#include "AnimationProperty.h"
#include "AnimationDataPosition.h"
#include "AnimationDataSprite.h"

__int64 AnimationProperty::KeyMaxTime() {
	if (_keys.empty()) {
		return 0;
	}

	return _keys.rbegin()->first;
}

AnimationProperty::AnimationProperty(AnimationPropertyType type)
: _type(type) {
	AddKey(0);
}

AnimationProperty::~AnimationProperty() {
}


void AnimationProperty::Update(__int64 time, GameObjectPtr ptr) {
	if (_keys.empty()) {
		return;
	}

	AnimationDataPtr before, end;
	GetData(time, before, end);

	before->Apply(time, ptr, end);
}

void AnimationProperty::GetData(__int64 time, AnimationDataPtr & before, AnimationDataPtr & end) {
	std::map<__int64, AnimationDataPtr>::iterator data = _keys.begin();
	std::map<__int64, AnimationDataPtr>::iterator iter = data;
	for (; iter != _keys.end(); ++iter) {
		if (iter->first > time) {
			break;
		}
		else {
			data = iter;
		}
	}

	before = data->second;
	end = (iter == _keys.end()) ? data->second : iter->second;
}

AnimationDataPtr AnimationProperty::AddKey(__int64 time) {
	std::map<__int64, AnimationDataPtr>::iterator iter = _keys.find(time);
	if (iter != _keys.end()) {
		return iter->second;
	}

	AnimationDataPtr tmp;
	switch (_type)
	{
	case ANIMATION_PROPERTY_POSITION:
		tmp = AnimationDataPositionPtr(new AnimationDataPosition(time));
		break;
	case ANIMATION_PROPERTY_SPRITE:
		tmp = AnimationDataSpritePtr(new AnimationDataSprite(time));
		break;
	default:
		break;
	}

	if (tmp) {
		_keys[time] = tmp;
	}

	return tmp;
}
