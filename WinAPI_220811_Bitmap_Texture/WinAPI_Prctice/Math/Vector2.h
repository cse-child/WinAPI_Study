#pragma once

// 여기서 오타를 치면 디버깅해서 찾기가 매~~우 어렵기 때문에 오타없이 신중하게 작성하기
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

	// 연산자 오버로딩
	Vector2 operator+(const Vector2& value) const
	{
		return Vector2(x + value.x, y + value.y);
	}
	// 뒤에 const -> 멤버변수를 건들이지 않겠다.
	Vector2 operator-(const Vector2& value) const
	{
		return Vector2(x - value.x, y - value.y);
	}

	Vector2 operator*(const float& value) const
	{
		return Vector2(x * value, y * value);
	}
	Vector2 operator/(const float& value) const
	{
		return Vector2(x / value, y / value);
	}

	void operator+=(const Vector2& value)
	{
		x += value.x;
		y += value.y;
	}
	void operator-=(const Vector2& value)
	{
		x -= value.x;
		y -= value.y;
	}
	void operator*=(const float& value)
	{
		x *= value;
		y *= value;
	}
	void operator/=(const float& value)
	{
		x /= value;
		y /= value;
	}

	float Length() const
	{
		return sqrtf(x * x + y * y);
	}

	float Angle() const
	{
		return atan2f(-y, x);
	}

	// 크기가 1인 방향벡터 반환
	Vector2 Normalized() const
	{
		float length = Length();

		return Vector2(x / length, y / length);
	}

	// 외적
	static float Cross(const Vector2& value1, const Vector2& value2)
	{
		return value1.y * value2.x - value1.x * value2.y;
	}
};