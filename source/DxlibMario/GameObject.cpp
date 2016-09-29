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
	SpriteRendererPtr tmp = SpriteRendererPtr( new SpriteRenderer(shared_from_this( )));
	_components.push_back(tmp);

	return tmp;
}

void GameObject::Render() {
	for (std::list<ComponentPtr>::const_iterator iter = _components.begin();
		iter != _components.end(); ++iter) {
		(*iter)->Render();
	}
}

void GameObject::Update() {
	
}

Vector GameObject::GetGlobalPosition() const {
	return _globalPosition;
}