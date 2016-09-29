#include "Renderer.h"
#include "GameEngine.h"

Renderer::~Renderer() {

}

Renderer::Renderer() {
}

RendererPtr Renderer::GetInstance() {
	return sGameEngine->GetRenderer();
}