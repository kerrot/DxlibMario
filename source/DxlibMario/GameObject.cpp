#include "GameObject.h"
#include "SpriteRenderer.h"

int GameObject::guid = 0;

GameObject::GameObject() 
: _guid(++guid){

}


GameObject::~GameObject() {
}

int GameObject::GetGuid() const {
	return _guid;
}

const std::list<ComponentPtr>& GameObject::GetComponents() const {
	return _components;
}

SpriteRendererPtr GameObject::AddSpriteRenderer() {
	SpriteRendererPtr tmp = SpriteRendererPtr( new SpriteRenderer());
	_components.push_back(tmp);

	return tmp;
}