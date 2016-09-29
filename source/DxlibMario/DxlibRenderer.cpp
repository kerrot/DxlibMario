#include "DxlibRenderer.h"
#include "DxLib.h"
#include "Sprite.h"
#include "mathmatics.h"

DxlibRenderer::DxlibRenderer() {
	DxLib_Init();
}


DxlibRenderer::~DxlibRenderer() {
	DxLib_End();
}

void DxlibRenderer::SetFullWindow(bool set) {
	ChangeWindowMode( set ? FALSE : TRUE);
}

int DxlibRenderer::SetResolution(int SizeX, int SizeY) {
	return SetGraphMode(SizeX, SizeY, 32);
}

int DxlibRenderer::LoadSprite(const char* filename) {
	return LoadGraph(filename);
}

void DxlibRenderer::RenderSprite(Vector pos, SpritePtr sprite) {
	DrawGraph( (int)pos.x , (int)pos.y , sprite->GetNum() , sprite->IsTransparent() ? TRUE : FALSE ) ;
}