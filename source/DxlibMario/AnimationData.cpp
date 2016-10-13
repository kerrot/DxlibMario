#include "AnimationData.h"



AnimationData::AnimationData(__int64 time) 
: _time(time) {
}


AnimationData::~AnimationData() {
}

__int64 AnimationData::GetTime() {
	return _time;
}
