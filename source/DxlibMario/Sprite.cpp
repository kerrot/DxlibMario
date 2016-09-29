#include "Sprite.h"

Sprite::Sprite(int num) 
: _num(num)
,_transparent(true) {

}

Sprite::~Sprite() {

}

int Sprite::GetNum() const {
	return _num;
}

bool Sprite::IsTransparent() const {
	return _transparent;
}