#pragma once
#include "Component.h"
#include "Common.h"

PTR( SpriteCollider )

class SpriteCollider : public Component {
	friend class GameObject;
public:
	virtual ~SpriteCollider();

	const Rect& GetRect();
	void SetCustomRange(const Rect & rect);

	void EnableTrace();

private:
	SpriteCollider(GameObjectPtr obj);

	bool _traceSprite;
	Rect _range;
};

