#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
#include "GameObject.h"

class GameObjectHelper {
public:
	template <class T>
	static std::shared_ptr<T> GetGameObjectComponent(GameObjectPtr obj);

private:
	GameObjectHelper ();
};


template <class T>
static std::shared_ptr<T> GameObjectHelper::GetGameObjectComponent(GameObjectPtr obj) {
	for (std::list<ComponentPtr>::const_iterator iter = obj._components.begin();
		iter != obj._components.end(); ++iter) {
		std::shared_ptr<T> tmp = std::dynamic_pointer_cast< T >(*iter);
		if (tmp) {
			return tmp;
		}
	}

	return 0;
}