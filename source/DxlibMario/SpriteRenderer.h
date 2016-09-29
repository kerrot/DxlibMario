#pragma once
#include "Component.h"
#include "smart_ptr.h"

PTR ( SpriteRenderer )
PTR ( Sprite )

class SpriteRenderer : public Component {
	friend class GameObject;
public:
	virtual ~SpriteRenderer();

	virtual void Render();

	void SetSprite(SpritePtr sprite);
	SpritePtr GetSprite() const;

private:
	SpriteRenderer(GameObjectPtr obj);

	SpritePtr _sprite;
};

