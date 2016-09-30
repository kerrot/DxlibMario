#pragma once

// up 0 down positive
// left 0 right positive
struct Rect {
	Rect() : _left(0), _right(0), _up(0), _down(0) {}
	Rect(unsigned int down, unsigned int right) : _left(0), _right(right), _up(0), _down(down) {}
	Rect(unsigned int left, unsigned int right, unsigned int up, unsigned int down) : _left(left), _right(right), _up(up), _down(down) {}

	unsigned int _left;
	unsigned int _right;
	unsigned int _up;
	unsigned int _down;
};