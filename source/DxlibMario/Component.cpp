#include "Component.h"

Component::~Component() {
}

Component::Component()
: _enabled(true) {

}

void Component::OnDestroy() {

}

void Component::Destroy() {
	OnDestroy();

	_gameobject.reset();
}

void Component::Render() {

}

bool Component::IsEnabled() const {
	return _enabled;
}

GameObjectPtr Component::GetGameObject() {
	return _gameobject;
}
