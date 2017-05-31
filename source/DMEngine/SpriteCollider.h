#pragma once
#include "Component.h"
#include "Common.h"

struct Vector;

PTR( SpriteCollider )
PTR( GameObject )

class SpriteCollider : public Component {
	friend class GameObject; // only gameobject can create this component
public:
	virtual ~SpriteCollider();

	const Rect& GetRect();
	void SetCustomRange(const Rect & rect);

	//auto adjust to sprite renderer setting
	void EnableTrace();

	//judge whether two colliders collision with velocity. (to prevent penetration)
	static bool CollideWith(GameObjectPtr obj, GameObjectPtr other, const Vector& velocity);

private:
	SpriteCollider();

	bool _traceSprite;
	Rect _range;
};

