#include "Common.h"

bool Rect::IsCollision(const Rect& rect1, const Rect& rect2) {
	bool tmp = rect1._right < rect2._left || rect1._left > rect2._right || rect1._down < rect2._up || rect1._up > rect2._down;

	return !tmp;
}

void Rect::Shift(int x, int y) {
	_left += x;
	_right += x;
	_up += y;
	_down += y;
}

bool LineSegmentOverlap(int segment1min, int segment1max, int segment2min, int segment2max) {
	return	(segment1min >= segment2min && segment1min < segment2max) ||
		(segment1max <= segment2max && segment2max > segment2min);
}