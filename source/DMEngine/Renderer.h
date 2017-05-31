#pragma once
#include "smart_ptr.h"

struct Vector;
struct Rect;

PTR( Renderer );
PTR( Sprite );

//fpr rendering method
class Renderer {
public:
	virtual ~Renderer() = 0;

	virtual void SetFullWindow(bool set) = 0;
	virtual int SetResolution(int SizeX, int SizeY) = 0;
	
	//return serial number refer to image
	virtual int LoadSprite(const char* filename) = 0;
	//render whole image
	virtual void RenderSprite(const Vector& pos, SpritePtr sprite) = 0;
	//render part of image
	virtual void RenderRectSprite(const Vector& pos, const Rect& rect, SpritePtr sprite, bool reverse) = 0;
	virtual void GetSpriteSize(int num, int* width, int* height) = 0;

	//clear whole screen
	virtual void Clear() = 0;
	//double buffer switch
	virtual void Flip() = 0;

	static RendererPtr GetInstance();
protected:
	Renderer();
};

#define sRenderer Renderer::GetInstance()