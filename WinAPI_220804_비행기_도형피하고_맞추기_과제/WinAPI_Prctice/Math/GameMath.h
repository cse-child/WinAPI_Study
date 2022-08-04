#pragma once

namespace GameMath
{
	int Random(const int& min, const int& max);
	UINT Random(const UINT& min, const UINT& max);
	float Random(const float& min, const float& max);

	int Distance(const POINT& x, const POINT& y);
	float Distance(const Vector2& x, const Vector2& y);
};