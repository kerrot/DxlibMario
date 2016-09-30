#include "Sprite.h"

Sprite::Sprite(int num, unsigned int width, unsigned int height)
: _num(num)
,_width(width)
,_height(height)
,_transparent(true) {

}

Sprite::~Sprite() {

}

int Sprite::GetNum() const {
	return _num;
}

unsigned int Sprite::GetWidth() const {
	return _width;
}

unsigned int Sprite::GetHeight() const {
	return _height;
}

bool Sprite::IsTransparent() const {
	return _transparent;
}