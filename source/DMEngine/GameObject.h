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
	friend class GameEngine;	// only game engine can create gameobject
	friend class GameObjectHelper; // for access other gameobject data
public:
	virtual ~GameObject();
	
	int GetGuid() const;

	void Render();

	void Update();
	void LastUpdate(); // update after all update done

	SpriteColliderPtr AddSpriteCollider();
	RigidBody2DPtr AddRigidBody2D();
	SpriteRendererPtr AddSpriteRenderer();
	AnimatorPtr AddAnimator();
	AnimationPtr AddAnimation();

	void AddBehavior(BehaviorPtr ptr);

	void SetParent(GameObjectPtr obj);

	void Translate(const Vector& pos);
	void SetGlobalPosition(const Vector& pos);
	void SetlocalPosition(const Vector& pos);

	Vector GetGlobalPosition() const;
	Vector GetLocalPosition() const;

protected:
	GameObject();

	// call by game engine and rigidbody to trigger collision event
	friend void GameObjectCollision(GameObjectPtr obj, GameObjectPtr other); 
	// check the collsion exit
	void UpdateCollision();
	void UpdateAnimation();

protected:
	int _guid;	// the unique number in the system
	static int guid; // counter for guid

	SpriteRendererPtr _spriteRenderer;
	RigidBody2DPtr _rigidBody2D;
	SpriteColliderPtr _collider;
	
	GameObjectPtr _nowCollider;
	GameObjectPtr _lastCollider;
	AnimatorPtr _animator;
	AnimationPtr _animation;

	GameObjectPtr _parent;
	
	Vector _localPosition;
	Vector _globalPosition;
	
	std::map<int, GameObjectPtr> _children;
	std::list<ComponentPtr> _components;	// build in component
	std::list<BehaviorPtr> _behaviours;		// custom script

private:
	void Destroy(); // called when gameengine destroy gameobject
};


