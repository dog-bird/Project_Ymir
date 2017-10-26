#pragma once

// return value for status?
// IEngineComponent has a dependancy with this.
enum Result
{
	R_OK,
	R_INVALID
};

struct Vec2D
{
	int x;
	int y;
};

struct Rect2D
{
	int x;
	int y;
	int width;
	int height;
};