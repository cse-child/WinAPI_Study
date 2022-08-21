#pragma once

class ShootingScene : public Scene
{
public:
    ShootingScene();
    ~ShootingScene();
        
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:
    void CollisionPlaneAndEnemy();
    void CollisionBulletAndEnemy();
    void CollisionBulletAndPlane();

private:
    Landscape * landscape;
    Plane * plane;
};