#pragma once

class Enemy : public ImageRect
{
private:
    enum ActionType
    {
        WALK, RUN, HURT
    };

    enum StateType
    {
        MOVE, TRACE
    };

    // 추적범위
    const float TRACE_DISTANCE = 400.0f;
    const float FIRE_DELAY_TIME = 1.0f;

public:
    Enemy();
    ~Enemy();
       
    void Update();
    void Render(HDC hdc);

    void Init();

    void Damage();

    void SetTarget(Rect* target) { this->target = target; }

private:
    void SetState();

    void Move();
    void Trace();
    void Fire();

    void EndDamage();
    
    void CreateAnimations();
    
    void SetAction(ActionType actionType);

private:
    float speed = 300.0f;
    float traceSpeed = 500.0f;
    float maxHp = 50.0f;
    float curHp = 50.0f;
    float fireTime = 0.0f;

    Vector2 direction;

    map<ActionType, Animation*> animations;

    ActionType curType = WALK;
    StateType stateType = MOVE;

    ProgressBar* hpBar;
    Rect* target;
};