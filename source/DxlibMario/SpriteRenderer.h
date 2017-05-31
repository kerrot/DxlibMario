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
	void SetRect(const Rect & rect);

	//the center point of rotation
	void SetPivot(int x, int y);
	void GetPivot(int& x, int& y);

	//flip horizontal 
	void SetReverse(bool v);

private:
	SpriteRenderer();

	virtual void OnDestroy();
private:
	bool _reverse; // is  horizontal flipped

	int _layer;

	int _pivotX;
	int _pivotY;

	SpritePtr _sprite; //source sprite
	Rect _rect; //local 
};

