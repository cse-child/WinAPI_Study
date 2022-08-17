#pragma once

class Enemy : public ImageRect
{
private:
    enum ActionType
    {
        WALK, RUN, HURT
    };

public:
    Enemy();
    ~Enemy();
       
    void Update();
    void Render(HDC hdc);

    void Init();

    void Damage();
private:
    void Move();
    void CreateAnimations();

private:
    float speed = 300.0f;
    float maxHp = 50.0f;
    float curHp = 50.0f;

    map<ActionType, Animation*> animations;

    ActionType curType = WALK;

    ProgressBar* hpBar;
};