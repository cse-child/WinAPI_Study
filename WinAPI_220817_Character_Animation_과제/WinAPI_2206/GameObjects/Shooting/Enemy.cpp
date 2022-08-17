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

    Move();

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
}

void Enemy::Damage()
{
    curHp -= 10.0f;

    hpBar->SetValue(curHp);

    if (curHp <= 0.0f)
        isActive = false;
}


void Enemy::Move()
{
    pos.x -= speed * DELTA;

    if (Right() < 0)
        isActive = false;
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
        animations[HURT]->SetArray(arr, ARRAYSIZE(arr), true);
    }
}
