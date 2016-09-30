#pragma once
#include "smart_ptr.h"
#include "Common.h"

PTR( Sprite );

class Sprite {
friend class GameEngine;
public:
	virtual ~Sprite();

	int GetNum() const; 
	const Rect& GetRect() const;

	bool IsTransparent() const;
	bool IsPartOnly() const;

	void SetDrawRect(const Rect& rect);
private:
	Sprite(int num);

	int _num;
	bool _transparent;
	bool _partOnly;

	Rect _range;
};