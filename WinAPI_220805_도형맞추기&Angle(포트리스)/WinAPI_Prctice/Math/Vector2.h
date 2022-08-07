#pragma once

struct Vector2
{
	float x = 0.0f;
	float y = 0.0f;

	Vector2() {}
	Vector2(float x, float y) : x(x), y(y) {}
	Vector2(POINT value)
	{
		x = (float)value.x;
		y = (float)value.y;
	}
};