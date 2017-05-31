#include "ObjectBase.h"



ObjectBase::ObjectBase()
: _enable(true) {
}


ObjectBase::~ObjectBase() {
}

bool ObjectBase::IsEnabled() const {
	return _enable;
}

void ObjectBase::SetEnable(bool v) {
	_enable = v;
}
