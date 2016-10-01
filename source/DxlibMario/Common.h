#pragma once

// up 0 down positive
// left 0 right positive
struct Rect {
	Rect() : _left(0), _right(0), _up(0), _down(0) {}
	Rect(int down, int right) : _left(0), _right(right), _up(0), _down(down) {}
	Rect(int left, int right, int up, int down) : _left(left), _right(right), _up(up), _down(down) {}

	int _left;
	int _right;
	int _up;
	int _down;

	static bool IsCollision(const Rect& rect1, const Rect& rect2);
};

inline bool Rect::IsCollision(const Rect& rect1, const Rect& rect2) {
	bool tmp = rect1._right < rect2._left || rect1._left > rect2._right || rect1._down < rect2._up || rect1._up > rect2._down;

	return !tmp;
}