#include "DxlibRenderer.h"
#include "DxLib.h"


DxlibRenderer::DxlibRenderer() {
	if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
	{
		return;        // エラーが起きたら直ちに終了
	}
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

int DxlibRenderer::LoadGraph(const char* filename) {
	return LoadGraph(filename);
}
