#pragma once
#include "Component.h"
#include "Common.h"

struct Vector;

PTR( SpriteCollider )
PTR( GameObject )

class SpriteCollider : public Component {
	friend class GameObject;
public:
	virtual ~SpriteCollider();

	const Rect& GetRect();
	void SetCustomRange(const Rect & rect);

	void EnableTrace();

	static bool CollideWith(GameObjectPtr obj, GameObjectPtr other, const Vector& velocity);

private:
	SpriteCollider();

	bool _traceSprite;
	Rect _range;
};

