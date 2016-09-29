#pragma once
#include "smart_ptr.h"
#include "mathmatics.h"
#include <list>

PTR( GameObject );
PTR( Component );
PTR( SpriteRenderer );

class GameObject : public std::enable_shared_from_this < GameObject > {
	friend class GameEngine;
public:
	virtual ~GameObject();
	
	int GetGuid() const;

	void Render();
	void Update();

	const std::list<ComponentPtr>& GetComponents() const;
	SpriteRendererPtr AddSpriteRenderer();

	Vector GetGlobalPosition() const;

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


