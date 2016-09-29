#pragma once
#include "smart_ptr.h"

struct Vector;

PTR( Renderer );
PTR( Sprite );

class Renderer {
public:
	virtual ~Renderer() = 0;

	virtual void SetFullWindow(bool set) = 0;
	virtual int SetResolution(int SizeX, int SizeY) = 0;
	
	virtual int LoadSprite(const char* filename) = 0;
	virtual void RenderSprite(Vector pos, SpritePtr sprite) = 0;

	virtual void Clear() = 0;
	virtual void Flip() = 0;

	static RendererPtr GetInstance();
protected:
	Renderer();
};

#define sRenderer Renderer::GetInstance()