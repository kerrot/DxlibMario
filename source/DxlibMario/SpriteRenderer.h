#pragma once
#include "Component.h"
#include "smart_ptr.h"

PTR (SpriteRenderer)

class SpriteRenderer : public Component {
public:
	SpriteRenderer();
	virtual ~SpriteRenderer();
};

