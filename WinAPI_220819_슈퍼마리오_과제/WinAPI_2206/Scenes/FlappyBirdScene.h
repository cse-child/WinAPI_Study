#pragma once

class FlappyBirdScene : public Scene
{
public:
    FlappyBirdScene();
    ~FlappyBirdScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:
    Landscape * landscape;
    Plane * plane;
};