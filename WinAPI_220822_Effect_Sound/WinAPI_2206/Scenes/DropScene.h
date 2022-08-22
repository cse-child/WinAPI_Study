#pragma once

class DropScene : public Scene
{
public:
    DropScene();
    ~DropScene();
        
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:
    void CollisionBulletAndDropCircle();

private:
    //DropCircle * dropCircle;
    Plane * plane;

    int score = 0;
};