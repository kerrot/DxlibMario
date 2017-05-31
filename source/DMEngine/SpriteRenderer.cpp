#include "SpriteRenderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Camera.h"
#include "GameEngine.h"

SpriteRenderer::SpriteRenderer() 
: _pivotX(0)
, _pivotY(0)
, _reverse(false) {
}

void SpriteRenderer::OnDestroy() {
	sGameEngine->ClearSpritetLayer(_layer, _gameobject->GetGuid());
}


SpriteRenderer::~SpriteRenderer() {
}

void SpriteRenderer::SetSprite(SpritePtr sprite) {
	_sprite = sprite; 

	_rect._right = _sprite->GetWidth();
	_rect._down = _sprite->GetHeight();
}

SpritePtr SpriteRenderer::GetSprite() const {
	return _sprite;
}

void SpriteRenderer::SetLayer(int layer) {
	// must call before change layer
	sGameEngine->SetSpritetLayer(layer, std::dynamic_pointer_cast<SpriteRenderer>(shared_from_this()));

	_layer = layer;
}

int SpriteRenderer::GetLayer() const {
	return _layer;
}

const Rect & SpriteRenderer::GetRect() const {
	return _rect;
}

void SpriteRenderer::SetRect(const Rect & rect) {
	_rect = rect;
}

void SpriteRenderer::SetPivot(int x, int y) {
	_pivotX = x;
	_pivotY = y;
}

void SpriteRenderer::GetPivot(int & x, int & y) {
	x = _pivotX;
	y = _pivotY;
}

void SpriteRenderer::RenderSprite() {
	if (!_sprite || !_gameobject->IsEnabled())
	{
		return;
	}
	// calculate the position to screen
	Vector pos = _gameobject->GetGlobalPosition() - sCamera->GetGlobalPosition();
	pos.x -= _pivotX;
	pos.y -= _pivotY;

	Rect tmpRect(_rect);

	tmpRect._down = _rect._down - _rect._up;
	tmpRect._right = _rect._right - _rect._left;

	sRenderer->RenderRectSprite(pos, tmpRect, _sprite, _reverse);
}

void SpriteRenderer::SetReverse(bool v) {
	_reverse = v;
}