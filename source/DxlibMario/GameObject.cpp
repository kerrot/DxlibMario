#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Behavior.h"

int GameObject::guid = 0;

GameObject::GameObject() 
: _guid(++guid){

}


GameObject::~GameObject() {
}

int GameObject::GetGuid() const {
	return _guid;
}

SpriteRendererPtr GameObject::AddSpriteRenderer() {
	SpriteRendererPtr tmp = SpriteRendererPtr( new SpriteRenderer(shared_from_this()));
	_components.push_back(tmp);

	return tmp;
}

void GameObject::Render() {
	for (std::list<ComponentPtr>::const_iterator iter = _components.begin();
		iter != _components.end(); ++iter) {
		if ((*iter)->IsEnabled()) {
			(*iter)->Render();
		}
	}
}

void GameObject::Update() {
	for (std::list<BehaviorPtr>::const_iterator iter = _behaviours.begin();
		iter != _behaviours.end(); ++iter) {
		if ((*iter)->IsEnabled()) {
			(*iter)->Update();
		}
	}
}

void GameObject::LastUpdate() {
	for (std::list<BehaviorPtr>::const_iterator iter = _behaviours.begin();
		iter != _behaviours.end(); ++iter) {
		if ((*iter)->IsEnabled()) {
			(*iter)->LastUpdate();
		}
	}
}

Vector GameObject::GetGlobalPosition() const {
	return _globalPosition;
}

Vector GameObject::GetLocalPosition() const {
	return _localPosition;
}

void GameObject::AddBehavior(BehaviorPtr ptr) {
	_components.push_back(ptr);
	_behaviours.push_back(ptr);
}

void GameObject::SetGlobalPosition(const Vector& pos) {
	_globalPosition = pos;
}

void GameObject::SetlocalPosition(const Vector& pos) {
	_localPosition = pos;
}
