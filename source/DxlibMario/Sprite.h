#pragma once
#include "smart_ptr.h"

PTR( Sprite );

class Sprite {
friend class GameEngine;
public:
	virtual ~Sprite();
private:
	Sprite(const char* fileName, int num);

	const char* _fileName;
	const int _num;
};