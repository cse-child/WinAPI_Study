#include "Framework.h"

Cookie::Cookie()
{
    CreateAnimations();

    pos = { CENTER_X, CENTER_Y };

    animations[curType]->Play();

    bodyRect = new Rect({CENTER_X, CENTER_Y}, {50, 70});
    bodyOffset.y = -30;

    bomb = new ImageRect(TEXTURE->Add(L"Textures/EnemyBullet.bmp", 54, 54));
    bomb->Active() = false;

    hBrush = CreateSolidBrush(MAGENTA);
    hPen = CreatePen(PS_SOLID, 1, MAGENTA);
}

Cookie::~Cookie()
{
    for (pair<ActionType, Animation*> animation : animations)
        delete animation.second;

    delete bodyRect;
    delete bomb;

    DeleteObject(hBrush);
    DeleteObject(hPen);
}

void Cookie::Update()
{
    Move();
    Jump();
    //CollisionLand();
    Attack();
    SetAnimation();

    animations[curType]->Update();

    //bodyRect->Pos() = pos + bodyOffset;
    pos = bodyRect->Pos() + bodyOffset;

    BombMove();
}

void Cookie::Render(HDC hdc)
{
    //bodyRect->Render(hdc);
    ImageRect::CamRender(hdc, animations[curType]->GetFrame());

    bomb->Render(hdc);
}

bool Cookie::CanMove()
{
    Vector2 tempPos = bodyRect->Pos();
    float nextHeight = 0.0f;

    if (isRight)
    {
        tempPos.x = bodyRect->Right();
    }
    else
    {
        tempPos.x = bodyRect->Left();
    }

    nextHeight = landTexture->GetPixelHeight(tempPos);

    if (bodyRect->Bottom() - nextHeight > SLOPE)
        return false;

    return true;
}

void Cookie::Move()
{
    bool isMove = false;

    if (KEY_PRESS(VK_RIGHT))
    {
        velocity.x += ACCEL * DELTA;
        
        if (velocity.x > MAX_VELOCITY)
            velocity.x = MAX_VELOCITY;
    }

    if (KEY_PRESS(VK_LEFT))
    {
        velocity.x -= ACCEL * DELTA;

        if (velocity.x < - MAX_VELOCITY)
            velocity.x = -MAX_VELOCITY;
    }

    // 선형보간 (t는 0부터 1사이의 값)
    // Start + (End - Start) * t(보간)
    // Start * (1-t) + E * t

    velocity.x = Clamp(-MAX_VELOCITY, MAX_VELOCITY, velocity.x);
    
    velocity.x = LERP(velocity.x, 0.0f, DECEL * DELTA);

    if(CanMove())
        bodyRect->Pos().x += velocity.x * DELTA;

    if (velocity.x > 0.0f)
        isRight = true;
    else if (velocity.x < 0.0f)
        isRight = false;

    // 오른쪽 왼쪽으로 못나가게 예외처리
    if (bodyRect->Left() < 0.0f)
        bodyRect->Pos().x = bodyRect->Half().x;

    if (bodyRect->Right() > landTexture->GetSize().x)
        bodyRect->Pos().x = landTexture->GetSize().x - bodyRect->Half().x;
}

void Cookie::Jump()
{
    if (jumpCount < MAX_JUMP_COUNT && KEY_DOWN(VK_UP))
    {
        velocity.y = JUMP_POWER;
        jumpCount++;

        if (jumpCount >= 2)
        {
            if (isRight)
                SetAction(ROLL_R);
            else
                SetAction(ROLL_L);
        }
    }

    velocity.y -= GRAVITY * DELTA;
    bodyRect->Pos().y -= velocity.y * DELTA;

    height = landTexture->GetPixelHeight(bodyRect->Pos());

    if (bodyRect->Bottom() > height) // 착지
    {

        jumpCount = 0;
        //bodyRect->Pos().y = WIN_HEIGHT - bodyRect->Half().y;
        bodyRect->Pos().y = height - bodyRect->Half().y;
        velocity.y = 0;
        //SetAction(RUN_R);
    }
}

void Cookie::SetAnimation()
{
    if (curType == ROLL_R || curType == ROLL_L) return;
    if (curType == ATTACK_R || curType == ATTACK_L) return;

    if (velocity.y > 1.0f)
    {
        if (isRight)
            SetAction(JUMP_UP_R);
        else
            SetAction(JUMP_UP_L);
        return;
    }
    else if (velocity.y < -1.0f)
    {
        if (isRight)
            SetAction(JUMP_DOWN_R);
        else
            SetAction(JUMP_DOWN_L);
        return;
    }

    if (velocity.x > 5.0f) // 오른쪽으로 진행중
        SetAction(RUN_R);
    else if (velocity.x < -5.0f) // 왼쪽으로 진행중
        SetAction(RUN_L);
    else
        SetAction(IDLE);
}

void Cookie::Attack()
{
    if (curType == ATTACK_R || curType == ATTACK_L) return;
    if (bomb->Active()) return;

    if (KEY_DOWN(VK_SPACE))
    {
        if (isRight)
        {
            SetAction(ATTACK_R);
            bombVelocity.x = 200;
        }
        else
        {
            SetAction(ATTACK_L);
            bombVelocity.x = -200;
        }

        bomb->Active() = true;
        bomb->Pos() = pos;
        bombVelocity.y = -300;
    }
}

void Cookie::BombMove()
{
    if (!bomb->Active()) return;

    bombVelocity.y += GRAVITY * DELTA;

    bomb->Pos() += bombVelocity * DELTA;

    float height = landTexture->GetPixelHeight(bomb->Pos());
    if (bomb->Pos().y > height)
    {
        bomb->Active() = false;

        SelectObject(landTexture->GetMemDC(), hBrush);
        SelectObject(landTexture->GetMemDC(), hPen);

        Ellipse(landTexture->GetMemDC(),
            (int)bomb->Left(), (int)bomb->Top(),
            (int)bomb->Right(), (int)bomb->Bottom());
    }
}

void Cookie::EndRoll()
{
    SetAction(IDLE);
}

void Cookie::EndAttack()
{
    SetAction(IDLE);
}

void Cookie::CollisionLand()
{
    Rect* rect = LandManager::Get()->IsCollision(bodyRect);

    if (rect == nullptr) return;
    if (velocity.y > 0) return;
    if (Bottom() > rect->Pos().y) return;

    bodyRect->Pos().y = rect->Top() - bodyRect->Half().y;
    jumpCount = 0;
    velocity.y = 0;
}


void Cookie::SetAction(ActionType type)
{
    if (curType == type) return;

    curType = type;
    animations[curType]->Play();
}

void Cookie::CreateAnimations()
{
    Texture* texture = TEXTURE->Add(L"Textures/Cookie.bmp", 1497, 1634, 11, 12);

    SetTexture(texture);

    // IDLE
    animations[IDLE] = new Animation(texture->GetFrame());
    animations[IDLE]->SetPart(24, 27, true);

    // JUMP_UP
    animations[JUMP_UP_R] = new Animation(texture->GetFrame());
    animations[JUMP_UP_R]->SetPart(0, 0, true);

    animations[JUMP_UP_L] = new Animation(texture->GetFrame());
    animations[JUMP_UP_L]->SetPart(76, 76, true);

    // JUMP_DOWN
    animations[JUMP_DOWN_R] = new Animation(texture->GetFrame());
    animations[JUMP_DOWN_R]->SetPart(5, 5, true);

    animations[JUMP_DOWN_L] = new Animation(texture->GetFrame());
    animations[JUMP_DOWN_L]->SetPart(71, 71, true);

    // ROLL
    animations[ROLL_R] = new Animation(texture->GetFrame());
    animations[ROLL_R]->SetPart(1, 4);
    animations[ROLL_R]->SetEndEvent(bind(&Cookie::EndRoll, this));

    animations[ROLL_L] = new Animation(texture->GetFrame());
    animations[ROLL_L]->SetReversePart(75, 72);
    animations[ROLL_L]->SetEndEvent(bind(&Cookie::EndRoll, this));

    // RUN
    animations[RUN_R] = new Animation(texture->GetFrame());
    animations[RUN_R]->SetPart(11, 18, true);

    animations[RUN_L] = new Animation(texture->GetFrame());
    animations[RUN_L]->SetReversePart(87, 80,true);

    // ATTACK
    animations[ATTACK_R] = new Animation(texture->GetFrame());
    animations[ATTACK_R]->SetPart(27, 30, false, true);
    animations[ATTACK_R]->SetEndEvent(bind(&Cookie::EndAttack, this));

    animations[ATTACK_L] = new Animation(texture->GetFrame());
    animations[ATTACK_L]->SetReversePart(93, 90, false, true);
    animations[ATTACK_L]->SetEndEvent(bind(&Cookie::EndAttack, this));
}
