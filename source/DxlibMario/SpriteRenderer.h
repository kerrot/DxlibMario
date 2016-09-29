#pragma once
#include "Component.h"
#include "smart_ptr.h"

PTR (SpriteRenderer)

class SpriteRenderer : public Component {
	friend class GameObject;
public:
	virtual ~SpriteRenderer();
private:
	SpriteRenderer();
};

