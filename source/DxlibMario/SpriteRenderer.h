#pragma once
#include "Component.h"
#include "smart_ptr.h"
#include "Common.h"

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

	const Rect& GetRect() const;
	void SetDrawRect(const Rect & rect);

	void SetPivot(int x, int y);
	void GetPivot(int& x, int& y);

private:
	SpriteRenderer(GameObjectPtr obj);

	SpritePtr _sprite;
	Rect _range;

	bool _partOnly;
	int _layer;

	int pivotX;
	int pivotY;
};

