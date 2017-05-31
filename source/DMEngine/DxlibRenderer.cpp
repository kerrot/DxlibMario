#include "DxlibRenderer.h"
#include "DxLib.h"
#include "Sprite.h"
#include "mathmatics.h"
#include "Common.h"

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

void DxlibRenderer::RenderSprite(const Vector& pos, SpritePtr sprite) {
	DrawGraph( (int)pos.x , (int)pos.y , sprite->GetNum() , sprite->IsTransparent() ? TRUE : FALSE ) ;
}

void DxlibRenderer::RenderRectSprite(const Vector& pos, const Rect& rect, SpritePtr sprite, bool reverse) {	
	DrawRectGraph((int)pos.x, (int)pos.y, rect._left, rect._up, rect._right, rect._down, 
		sprite->GetNum(), sprite->IsTransparent() ? TRUE : FALSE, 
		(reverse) ? TRUE : FALSE);
}

void DxlibRenderer::GetSpriteSize(int num, int* width, int* height) {
	GetGraphSize(num, width, height);
}

void DxlibRenderer::Clear() {
	ClearDrawScreen();
}

void DxlibRenderer::Flip() {
	ScreenFlip();
}
