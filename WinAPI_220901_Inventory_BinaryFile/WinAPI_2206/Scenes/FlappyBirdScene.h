#pragma once

class FlappyBirdScene : public Scene
{
public:
    FlappyBirdScene();
    ~FlappyBirdScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

    virtual void Start() override;
    virtual void End() override;

private:
    Landscape * landscape;
    Plane * plane;
};