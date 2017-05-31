#include "Component.h"

Component::~Component() {
}

Component::Component() {

}

void Component::OnDestroy() {

}

void Component::Destroy() {
	OnDestroy();

	_gameobject.reset();
}

void Component::Render() {

}

GameObjectPtr Component::GetGameObject() {
	return _gameobject;
}
