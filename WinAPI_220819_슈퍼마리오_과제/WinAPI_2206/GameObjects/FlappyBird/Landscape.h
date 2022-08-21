#pragma once

class Landscape
{
public:
    Landscape();
    ~Landscape();

    void Update();
    void Render(HDC hdc);

private:
    ImageRect * bgs[2];

    float speed = 50;
};