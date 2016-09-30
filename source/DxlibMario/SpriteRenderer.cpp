#include "SpriteRenderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Camera.h"
#include "GameEngine.h"

SpriteRenderer::SpriteRenderer(GameObjectPtr obj) 
: Component(obj)  {
}


SpriteRenderer::~SpriteRenderer() {
}

void SpriteRenderer::SetSprite(SpritePtr sprite) {
	_sprite = sprite; 
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

void SpriteRenderer::RenderSprite() {
	if (!_sprite)
	{
		return;
	}

	if (_sprite->IsPartOnly()) {
		sRenderer->RenderRectSprite(_gameobject->GetGlobalPosition() - sCamera->GetGlobalPosition(), _sprite);
	}
	else {
		sRenderer->RenderSprite(_gameobject->GetGlobalPosition() - sCamera->GetGlobalPosition(), _sprite);
	}
}