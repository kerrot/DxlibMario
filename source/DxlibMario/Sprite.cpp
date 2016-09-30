#include "Sprite.h"

Sprite::Sprite(int num) 
: _num(num)
,_transparent(true)
,_partOnly(false){

}

Sprite::~Sprite() {

}

int Sprite::GetNum() const {
	return _num;
}

const Rect & Sprite::GetRect() const {
	return _range;
}

bool Sprite::IsTransparent() const {
	return _transparent;
}

bool Sprite::IsPartOnly() const {
	return _partOnly;
}

void Sprite::SetDrawRect(const Rect & rect) {
	_partOnly = true;
	_range = rect;
}
