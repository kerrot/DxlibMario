#pragma once
#include "smart_ptr.h"

PTR( Sprite );

class Sprite {
friend class GameEngine;
public:
	virtual ~Sprite();

	int GetNum() const; 
	bool IsTransparent() const;
private:
	Sprite(int num);

	int _num;
	bool _transparent;
};