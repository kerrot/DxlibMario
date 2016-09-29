#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include <list>

PTR( GameObject );
PTR( Component );
PTR( Behavior );
PTR( SpriteRenderer );

class GameObject : public std::enable_shared_from_this < GameObject > {
friend class GameEngine;
friend class GameObjectHelper;
public:
	virtual ~GameObject();
	
	int GetGuid() const;

	void Render();

	void Update();
	void LastUpdate();

	
	SpriteRendererPtr AddSpriteRenderer();
	void AddBehavior(BehaviorPtr ptr);

	void SetGlobalPosition(const Vector& pos);
	void SetlocalPosition(const Vector& pos);

	Vector GetGlobalPosition() const;
	Vector GetLocalPosition() const;

protected:
	GameObject();

	Vector _localPosition;
	Vector _globalPosition;

	GameObjectPtr _parent;
	std::list<GameObjectPtr> _children;
	std::list<ComponentPtr> _components;
	std::list<BehaviorPtr> _behaviours;	

	int _guid;
	static int guid;

	
};


