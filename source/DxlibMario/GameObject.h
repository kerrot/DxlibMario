#pragma once
#include "ObjectBase.h"
#include "mathmatics.h"
#include <list>
#include <map>

PTR( GameObject );
PTR( Component );
PTR( Behavior );
PTR( SpriteRenderer );
PTR( RigidBody2D );
PTR( SpriteCollider );
PTR( Animator )
PTR( Animation )

class GameObject : public ObjectBase {
	friend class GameEngine;
friend class GameObjectHelper;
public:
	virtual ~GameObject();
	
	int GetGuid() const;

	void Render();

	void Update();
	void LastUpdate();

	SpriteColliderPtr AddSpriteCollider();
	RigidBody2DPtr AddRigidBody2D();
	SpriteRendererPtr AddSpriteRenderer();
	AnimatorPtr AddAnimator();
	AnimationPtr AddAnimation();

	void AddBehavior(BehaviorPtr ptr);

	void SetParent(GameObjectPtr obj);

	void SetGlobalPosition(const Vector& pos);
	void SetlocalPosition(const Vector& pos);

	Vector GetGlobalPosition() const;
	Vector GetLocalPosition() const;

protected:
	GameObject();

	friend void GameObjectCollision(GameObjectPtr obj, GameObjectPtr other);
	void UpdateCollision();
	void UpdateAnimation();

	Vector _localPosition;
	Vector _globalPosition;

	GameObjectPtr _parent;
	std::map<int, GameObjectPtr> _children;
	std::list<ComponentPtr> _components;
	std::list<BehaviorPtr> _behaviours;	

	
	int _guid;
	static int guid;

	SpriteRendererPtr _spriteRenderer;
	RigidBody2DPtr _rigidBody2D;
	SpriteColliderPtr _collider;
	
	GameObjectPtr _nowCollider;
	GameObjectPtr _lastCollider;
	AnimatorPtr _animator;
	AnimationPtr _animation;

	std::map<int, SpriteColliderPtr> _colliderObjs;

private:
	void Destroy();
};


