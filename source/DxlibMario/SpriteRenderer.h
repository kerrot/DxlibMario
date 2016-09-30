#pragma once
#include "Component.h"
#include "smart_ptr.h"

PTR ( SpriteRenderer )
PTR ( Sprite )

class SpriteRenderer : public Component {
	friend class GameObject;
public:
	virtual ~SpriteRenderer();

	void RenderSprite();

	void SetSprite(SpritePtr sprite);
	SpritePtr GetSprite() const;

	void SetLayer(int layer);
	int GetLayer() const;

private:
	SpriteRenderer(GameObjectPtr obj);

	SpritePtr _sprite;

	int _layer;
};

