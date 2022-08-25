#pragma once

class Bullet : public ImageRect
{
public:
    Bullet(Texture* texture);
    ~Bullet();

    void Update();
    void Render(HDC hdc);

    void Fire(Vector2 pos);
    void Fire(Vector2 pos, float angle);
    void Fire(Vector2 pos, Vector2 direction);
        
private:
    float speed = 1000.0f;
    float angle = PI / 2;
    Vector2 direction;
};