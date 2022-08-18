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

    Vector2 operator+(const Vector2 & value) const
    {
        return Vector2(x + value.x, y + value.y);
    }
    Vector2 operator-(const Vector2 & value) const
    {
        return Vector2(x - value.x, y - value.y);
    }

    Vector2 operator*(const float & value) const
    {
        return Vector2(x * value, y * value);
    }
    Vector2 operator/(const float & value) const
    {
        return Vector2(x / value, y / value);
    }

    void operator+=(const Vector2 & value)
    {
        x += value.x;
        y += value.y;
    }
    void operator-=(const Vector2 & value)
    {
        x -= value.x;
        y -= value.y;
    }

    void operator*=(const float & value)
    {
        x *= value;
        y *= value;
    }
    void operator/=(const float & value)
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

    //ũ�Ⱑ 1�� ������� ��ȯ
    Vector2 Normalized() const
    {
        float length = Length();

        return Vector2(x / length, y / length);
    }

    static float Cross(const Vector2 & value1, const Vector2 & value2)
    {
        return value1.y * value2.x - value1.x * value2.y;
    }
};