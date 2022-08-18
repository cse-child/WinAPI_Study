#include "Framework.h"

Cookie::Cookie()
{
    CreateAnimations();

    pos = { CENTER_X, CENTER_Y };

    animations[curType]->Play();
}

Cookie::~Cookie()
{
    for (pair<ActionType, Animation*> animation : animations)
        delete animation.second;
}

void Cookie::Update()
{
    Move();
    Jump();

    animations[curType]->Update();
}

void Cookie::Render(HDC hdc)
{
    ImageRect::Render(hdc, animations[curType]->GetFrame());
}

void Cookie::Move()
{
}

void Cookie::Jump()
{
    if (jumpCount < MAX_JUMP_COUNT && KEY_DOWN(VK_SPACE))
    {
        velocity.y = JUMP_POWER;
        jumpCount++;

        if (jumpCount >= 2)
            SetAction(ROLL);
    }

    velocity.y -= GRAVITY * DELTA;
    pos.y -= velocity.y * DELTA;

    if (curType != ROLL && jumpCount > 0) // 뛰고있을때
    {
        if (velocity.y > 0) // 올라가는중
            SetAction(JUMP_UP);
        else // 내려가는중
            SetAction(JUMP_DOWN);
    }

    if (Bottom() > WIN_HEIGHT) // 착지
    {
        jumpCount = 0;
        pos.y = WIN_HEIGHT - Half().y;
        SetAction(RUN);
    }
}

void Cookie::EndRoll()
{
    SetAction(IDLE);
}

void Cookie::SetAction(ActionType type)
{
    if (curType == type) return;

    curType = type;
    animations[curType]->Play();
}

void Cookie::CreateAnimations()
{
    Texture* texture = TEXTURE->Add(L"Textures/Cookie.bmp", 1497, 817, 11, 6);

    SetTexture(texture);

    // IDLE
    animations[IDLE] = new Animation(texture->GetFrame());
    animations[IDLE]->SetPart(24, 27, true);

    // JUMP_UP
    animations[JUMP_UP] = new Animation(texture->GetFrame());
    animations[JUMP_UP]->SetPart(0, 0, true);

    // JUMP_DOWN
    animations[JUMP_DOWN] = new Animation(texture->GetFrame());
    animations[JUMP_DOWN]->SetPart(5, 5, true);

    // ROLL
    animations[ROLL] = new Animation(texture->GetFrame());
    animations[ROLL]->SetPart(1, 4);
    animations[ROLL]->SetEndEvent(bind(&Cookie::EndRoll, this));

    // RUN
    animations[RUN] = new Animation(texture->GetFrame());
    animations[RUN]->SetPart(11, 18, true);
}
