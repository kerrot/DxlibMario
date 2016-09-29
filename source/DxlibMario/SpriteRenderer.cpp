#include "SpriteRenderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "GameObject.h"

SpriteRenderer::SpriteRenderer(GameObjectPtr obj) 
: Component(obj) {
}


SpriteRenderer::~SpriteRenderer() {
}

void SpriteRenderer::SetSprite(SpritePtr sprite) {
	_sprite = sprite; 
}

SpritePtr SpriteRenderer::GetSprite() const {
	return _sprite;
}

void SpriteRenderer::Render() {
	sRenderer->RenderSprite(_gameobject->GetGlobalPosition() , _sprite);
}