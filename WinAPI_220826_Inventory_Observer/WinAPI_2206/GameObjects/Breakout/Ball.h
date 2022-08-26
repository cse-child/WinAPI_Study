#pragma once

class Ball : public Circle
{
public:
    Ball();
    ~Ball();

    void Update();
    void Render(HDC hdc);

    void SetBarRect(Rect * rect) { barRect = rect; }

private:
    void Move();

    void CollisionBorder();
    void CollisionBar();
    void CollisionBrick();

private:
    float speed = 300;
    Vector2 direction;

    HBRUSH hBrush;

    Rect * barRect;

    bool isPlay = false;
};