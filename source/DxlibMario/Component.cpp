#include "Component.h"

Component::~Component() {
}

Component::Component(GameObjectPtr obj)
: _gameobject(obj) 
, _enabled(true) {

}

void Component::Render() {

}

bool Component::IsEnabled() const {
	return _enabled;
}