#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include <list>

PTR( GameObject );
PTR( Component );
PTR( SpriteRenderer );

class GameObject {
	friend class GameEngine;
public:
	virtual ~GameObject();
	
	int GetGuid() const;

	const std::list<ComponentPtr>& GetComponents() const;
	SpriteRendererPtr AddSpriteRenderer();

private:
	GameObject();

	Vector _localPosition;
	Vector _globalPosition;

	GameObjectPtr _parent;
	std::list<GameObjectPtr> _children;
	std::list<ComponentPtr> _components;
	
	int _guid;
	static int guid;

	
};


