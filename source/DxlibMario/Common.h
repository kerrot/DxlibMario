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

	void Shift(int x, int y);
};

bool LineSegmentOverlap(int segment1min, int segment1max, int segment2min, int segment2max);