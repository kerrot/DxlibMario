#pragma once
#include "smart_ptr.h"

PTR(Renderer);

class Renderer {
public:
	virtual ~Renderer() = 0;

	virtual void SetFullWindow(bool set) = 0;
	virtual int SetResolution(int SizeX, int SizeY) = 0;
	virtual int LoadGraph(const char* filename) = 0;
protected:
	Renderer() { }
};