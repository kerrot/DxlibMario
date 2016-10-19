#include "AnimationDataEnable.h"
#include "ObjectBase.h"

AnimationDataEnable::AnimationDataEnable(__int64 time)
: AnimationData(time) {
}

AnimationDataEnable::~AnimationDataEnable() {
}

void AnimationDataEnable::Apply(__int64 time, GameObjectPtr ptr, AnimationDataPtr next) {
	if (!ptr) {
		return;
	}

	AnimationDataEnablePtr data = std::dynamic_pointer_cast<AnimationDataEnable>(next);
	if (!data) {
		return;
	}

	if (time >  next->GetTime()) {
		data->Apply();
	}
	else {
		Apply();
	}
}

void AnimationDataEnable::Apply() {
	if (_obj.expired()) {
		return;
	}

	ObjectBasePtr ptr = _obj.lock();
	ptr->SetEnable(_enable);
}

void AnimationDataEnable::SetEnable(ObjectBaseWPtr obj, bool enable) {
	_obj = obj;
	_enable = enable;
}
