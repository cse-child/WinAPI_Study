#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
{
    SetTexture(TEXTURE->Add(L"Textures/Cat.bmp", 949, 474, 7, 4));

    isActive = false;

    CreateAnimations();

    curType = RUN;
    animations[curType]->Play();

    Texture* frontImage = TEXTURE->Add(L"Textures/FrontHpbar.bmp", 337, 44);
    Texture* backImage = TEXTURE->Add(L"Textures/BackHpbar.bmp", 338, 40);

    hpBar = new ProgressBar(frontImage, backImage, maxHp);
    hpBar->Size() *= 0.3;    
}

Enemy::~Enemy()
{
    for (pair<ActionType, Animation*> animation : animations)
    {
        delete animation.second;
    }

    delete hpBar;
}

void Enemy::Update()
{
    if (!isActive) return;

    SetState();

    switch (stateType)
    {
    case Enemy::MOVE:
        Move();
        break;
    case Enemy::TRACE:
        Trace();
        break;
    }

    animations[curType]->Update();

    hpBar->Pos().x = pos.x;
    hpBar->Pos().y = Top() + hpBar->Size().y;
}

void Enemy::Render(HDC hdc)
{
    if (!isActive) return;

    texture->Render(hdc, this, animations[curType]->GetFrame());
    hpBar->Render(hdc);
}

void Enemy::Init()
{
    isActive = true;

    pos.x = WIN_WIDTH + Half().x;
    pos.y = Random(Half().y, WIN_HEIGHT - Half().y);

    hpBar->SetValue(maxHp);
    curHp = maxHp;

    SetAction(WALK);
}

void Enemy::Damage()
{
    //if (curType == HURT) return;

    curHp -= 10.0f;

    hpBar->SetValue(curHp);

    //SetAction(HURT);
    curType = HURT;
    animations[curType]->Play();

    if (curHp <= 0.0f)
        isActive = false;
}


void Enemy::SetState()
{
    direction = target->Pos() - pos;

    if (direction.Length() > TRACE_DISTANCE)
    {
        stateType = MOVE;
    }
    else
    {
        if (target->Pos().x > pos.x)
            stateType = MOVE;
        else
            stateType = TRACE;
    }
}

void Enemy::Move()
{
    if (curType == HURT) return;

    SetAction(WALK);

    pos.x -= speed * DELTA;

    if (Right() < 0)
        isActive = false;

    Fire();
}

void Enemy::Trace()
{
    if (curType == HURT) return;

    SetAction(RUN);

    pos += direction.Normalized() * traceSpeed * DELTA;

    if (Right() < 0)
        isActive = false;
}

void Enemy::Fire()
{
    fireTime += DELTA;

    if (fireTime >= FIRE_DELAY_TIME)
    {
        fireTime -= FIRE_DELAY_TIME;

        BulletManager::Get()->Fire("Enemy", pos, direction.Normalized());
    }
}

void Enemy::EndDamage()
{
    SetAction(WALK);
}

void Enemy::CreateAnimations()
{
    {
        // WALK
        animations[WALK] = new Animation(texture->GetFrame());
        int arr[] = { 15, 14, 27, 26, 25, 24, 23, 22, 21, 20 };
        animations[WALK]->SetArray(arr, ARRAYSIZE(arr), true);
    }
    {
        // RUN
        animations[RUN] = new Animation(texture->GetFrame());
        int arr[] = { 10, 9, 8, 7, 20, 19, 18, 17 };
        animations[RUN]->SetArray(arr, ARRAYSIZE(arr), true);
    }
    {
        // HURT
        animations[HURT] = new Animation(texture->GetFrame());
        int arr[] = { 6, 5, 4, 3, 2, 1, 0, 13, 12, 11 };
        animations[HURT]->SetArray(arr, ARRAYSIZE(arr));
        // 함수포인터 사용
        animations[HURT]->SetEndEvent(bind(&Enemy::EndDamage, this));
    }
}

void Enemy::SetAction(ActionType actionType)
{
    if (curType == actionType) return;

    curType = actionType;
    animations[curType]->Play();
}
