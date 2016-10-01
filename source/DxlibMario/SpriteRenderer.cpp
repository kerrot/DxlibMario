#include "SpriteRenderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Camera.h"
#include "GameEngine.h"

SpriteRenderer::SpriteRenderer(GameObjectPtr obj) 
: Component(obj)
, pivotX(0)
, pivotY(0) {
}


SpriteRenderer::~SpriteRenderer() {
}

void SpriteRenderer::SetSprite(SpritePtr sprite) {
	_sprite = sprite; 

	_range._right = _sprite->GetWidth();
	_range._down = _sprite->GetHeight();
}

SpritePtr SpriteRenderer::GetSprite() const {
	return _sprite;
}

void SpriteRenderer::SetLayer(int layer) {
	// must call before change layer
	sGameEngine->SetLayer(layer, std::dynamic_pointer_cast<SpriteRenderer>(shared_from_this()));

	_layer = layer;
}

int SpriteRenderer::GetLayer() const {
	return _layer;
}

const Rect & SpriteRenderer::GetRect() const {
	return _range;
}

void SpriteRenderer::SetDrawRect(const Rect & rect) {
	_range = rect;
}

void SpriteRenderer::SetPivot(int x, int y) {
	pivotX = x;
	pivotY = y;
}

void SpriteRenderer::GetPivot(int & x, int & y) {
	x = pivotX;
	y = pivotY;
}

void SpriteRenderer::RenderSprite() {
	if (!_sprite)
	{
		return;
	}

	Vector pos = _gameobject->GetGlobalPosition() - sCamera->GetGlobalPosition();
	pos.x -= pivotX;
	pos.y -= pivotY;

	sRenderer->RenderRectSprite(pos, _range, _sprite);
}