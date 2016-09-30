#pragma once
#include "Renderer.h"
#include "smart_ptr.h"

PTR(DxlibRenderer);

class DxlibRenderer : public Renderer {
friend class GameEngine;
public:
	virtual ~DxlibRenderer();

	virtual void SetFullWindow(bool set);
	virtual int SetResolution(int SizeX, int SizeY);
	virtual int LoadSprite(const char* filename);
	virtual void RenderSprite(const Vector& pos, SpritePtr sprite);
	virtual void RenderRectSprite(const Vector& pos, SpritePtr sprite);

	virtual void Clear();
	virtual void Flip();
private:
	DxlibRenderer();
};