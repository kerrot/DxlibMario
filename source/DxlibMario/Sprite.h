#pragma once
#include "smart_ptr.h"
#include "Common.h"

PTR( Sprite );

class Sprite {
friend class GameEngine;
public:
	virtual ~Sprite();

	int GetNum() const; 

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	bool IsTransparent() const;
private:
	Sprite(int num, unsigned int width, unsigned int height);

	int _num;
	bool _transparent;
	
	unsigned int _width;
	unsigned int _height;
};