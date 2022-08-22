#pragma once

class ControlBar : public Rect
{
public:
    ControlBar();
    ~ControlBar();

    void Update();
    void Render(HDC hdc);

private:
    float speed = 200.0f;

    HBRUSH hBrush;
};