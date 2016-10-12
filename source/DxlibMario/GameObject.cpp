#include "GameObject.h"
#include "SpriteRenderer.h"
#include "RigidBody2D.h"
#include "SpriteCollider.h"
#include "Animator.h"
#include "Animation.h"
#include "Behavior.h"
#include "GameObjectHelper.h"

int GameObject::guid = 0;

GameObject::GameObject() 
: _guid(++guid)
, _enabled(true) {

}

GameObject::~GameObject() {

}

void GameObjectCollision(GameObjectPtr obj, GameObjectPtr other) {
	if (obj->_lastCollider == other)
	{
		for (std::list<BehaviorPtr>::const_iterator iter = obj->_behaviours.begin();
			iter != obj->_behaviours.end(); ++iter) {
			if ((*iter)->IsEnabled()) {
				(*iter)->CollisionStay(other);
			}
		}
	}
	else {
		for (std::list<BehaviorPtr>::const_iterator iter = obj->_behaviours.begin();
			iter != obj->_behaviours.end(); ++iter) {
			if ((*iter)->IsEnabled()) {
				(*iter)->CollisionEnter(other);
			}
		}
	}

	obj->_nowCollider = other;
}

void GameObject::UpdateCollision() {
	if (_lastCollider != _nowCollider)	{
		for (std::list<BehaviorPtr>::const_iterator iter = _behaviours.begin();
			iter != _behaviours.end(); ++iter) {
			if ((*iter)->IsEnabled()) {
				(*iter)->CollisionExit(_lastCollider);
			}
		}
	}

	_lastCollider = _nowCollider;
}

void GameObject::UpdateAnimation() {
	if (_animator && _animator->IsEnabled()) {
		_animator->Update();
	}

	if (_animation && _animation->IsEnabled()) {
		_animation->Update();
	}
}

void GameObject::Destroy() {
	for (std::list<ComponentPtr>::const_iterator iter = _components.begin();
		iter != _components.end(); ++iter) {
			
		(*iter)->Destroy();
	}
}

int GameObject::GetGuid() const {
	return _guid;
}

SpriteColliderPtr GameObject::AddSpriteCollider() {
	if (!_collider) {
		SpriteColliderPtr tmp = SpriteColliderPtr(new SpriteCollider());
		tmp->_gameobject = shared_from_this();

		_components.push_back(tmp);
		_collider = tmp;
	}

	return _collider;
}

RigidBody2DPtr GameObject::AddRigidBody2D() {
	if (!_rigidBody2D) {
		RigidBody2DPtr tmp = RigidBody2DPtr(new RigidBody2D());
		tmp->_gameobject = shared_from_this();

		_components.push_back(tmp);
		_rigidBody2D = tmp;
	}

	return _rigidBody2D;
}

SpriteRendererPtr GameObject::AddSpriteRenderer() {
	if (!_spriteRenderer) {
		SpriteRendererPtr tmp = SpriteRendererPtr(new SpriteRenderer());
		tmp->_gameobject = shared_from_this();

		_components.push_back(tmp);
		_spriteRenderer = tmp;
		_spriteRenderer->SetLayer(0);
	}

	return _spriteRenderer;
}

AnimatorPtr GameObject::AddAnimator() {
	if (!_animator) {
		AnimatorPtr tmp = AnimatorPtr(new Animator());
		tmp->_gameobject = shared_from_this();
		_components.push_back(tmp);
		_animator = tmp;
	}

	return _animator;
}

AnimationWPtr GameObject::AddAnimation() {
	if (!_animation) {
		AnimationPtr tmp = AnimationPtr(new Animation());
		tmp->_gameobject = shared_from_this();
		_components.push_back(tmp);
		_animation = tmp;
	}

	return _animation;
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
	if (_rigidBody2D && _rigidBody2D->IsEnabled()) {
		_rigidBody2D->Update();
	}

	UpdateCollision();

	for (std::list<BehaviorPtr>::const_iterator iter = _behaviours.begin();
		iter != _behaviours.end(); ++iter) {
		if ((*iter)->IsEnabled()) {
			(*iter)->Update();
		}
	}

	UpdateAnimation();
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

bool GameObject::IsEnabled() const {
	return _enabled;
}

void GameObject::SetEnable(bool v) {
	_enabled = v;
}

void GameObject::AddBehavior(BehaviorPtr ptr) {
	ptr->_gameobject = shared_from_this();

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
