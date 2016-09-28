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
	
	int GetGuid();

	

	//template <class T, class TPtr>
	//TPtr GetComponent();

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

//template <class T, class TPtr>
//inline TPtr GameObject::GetComponent() {
//	for (std::list<ComponentPtr>::iterator iter = _components.begin();
//		iter != _components.end(); ++iter) {
//		TPtr tmp = std::dynamic_pointer_cast< T >(*iter);
//		if (tmp != 0) {
//			return tmp;
//		}
//	}
//
//	return 0;
//}
