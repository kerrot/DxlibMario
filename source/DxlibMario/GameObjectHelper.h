#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
#include "GameObject.h"

template <class T>
std::shared_ptr<T> GetGameObjectComponent(GameObjectPtr obj) {
	const std::list<ComponentPtr>& components = obj->GetComponents();
	for (std::list<ComponentPtr>::const_iterator iter = components.begin();
		iter != components.end(); ++iter) {
		std::shared_ptr<T> tmp = std::dynamic_pointer_cast< T >(*iter);
		if (tmp) {
			return tmp;
		}
	}

	return 0;
}