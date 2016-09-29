#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Behavior.h"
#include "GameObjectHelper.h"

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

void GameObject::SetParent(GameObjectPtr obj) {
	_parent = obj;

	GameObjectHelper::AddToGameObjectChildren(obj, shared_from_this());

	Vector parentPos = (obj == 0) ? Vector() : obj->GetGlobalPosition();
	_localPosition = _globalPosition - parentPos;
}

void GameObject::SetGlobalPosition(const Vector& pos) {
	Vector parentPos = (_parent == 0) ? Vector() : _parent->GetGlobalPosition();
	_localPosition = pos - parentPos;

	for(std::map<int, GameObjectPtr>::iterator iter = _children.begin();
		iter != _children.end(); ++iter)
	{
		iter->second->SetGlobalPosition(pos - _globalPosition + iter->second->GetGlobalPosition());
	}

	_globalPosition = pos;
}

void GameObject::SetlocalPosition(const Vector& pos) {
	Vector parentPos = (_parent == 0) ? Vector() : _parent->GetGlobalPosition();
	_globalPosition = parentPos + pos;

	for (std::map<int, GameObjectPtr>::iterator iter = _children.begin();
		iter != _children.end(); ++iter)
	{
		iter->second->SetGlobalPosition(pos - _localPosition + iter->second->GetGlobalPosition());
	}

	_localPosition = pos;
}
