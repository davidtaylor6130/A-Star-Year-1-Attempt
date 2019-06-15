#pragma once

struct Rect2D
{
	int x;
	int y;
	int width;
	int height;

	Rect2D() {
		x = y = width = height = 0;
	}

	Rect2D(int _x, int _y, int w, int h) {
		x = _x;
		y = _y;
		width = w;
		height = h;
	}
};

struct Vector2D 
{
	int x, y;

	Vector2D() {
		x = 0;
		y = 0;
	};

	Vector2D(int _x, int _y) {
		x = _x;
		y = _y;
	}
};