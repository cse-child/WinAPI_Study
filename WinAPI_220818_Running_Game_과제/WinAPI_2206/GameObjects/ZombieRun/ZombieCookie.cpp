#include "Framework.h"
#include "ZombieCookie.h"

ZombieCookie::ZombieCookie()
{
	CreateAnimations();

	pos = { CENTER_X, CENTER_Y };
    curType = START;
    size *= 1.3f;

	animations[curType]->Play();

    collisionRect = new Rect({ CENTER_X, CENTER_Y+50}, { 100, 100 });
}

ZombieCookie::~ZombieCookie()
{
	for (pair<ActionType, Animation*> animation : animations)
		delete animation.second;

    delete collisionRect;
}

void ZombieCookie::Update()
{
	Jump();

	animations[curType]->Update();

    collisionRect->Pos() = { pos.x, pos.y + 50 };
}

void ZombieCookie::Render(HDC hdc)
{
	ImageRect::Render(hdc, animations[curType]->GetFrame());
    
    collisionRect->LineRender(hdc);
}


void ZombieCookie::SetLanding()
{
    jumpCount = 0;
    SetAction(RUN);
}

void ZombieCookie::Jump()
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

    
}

void ZombieCookie::EndRoll()
{
    SetAction(RUN);
}

void ZombieCookie::SetAction(ActionType type)
{
    if (curType == type) return;

    curType = type;
    animations[curType]->Play();
}

void ZombieCookie::CreateAnimations()
{
    Texture* texture = TEXTURE->Add(L"Textures/ZombieCookie.bmp", 2416, 967, 15, 6);
    SetTexture(texture);

    // START
    animations[START] = new Animation(texture->GetFrame());
    animations[START]->SetPart(0, 7, true);

    // RUN
    animations[RUN] = new Animation(texture->GetFrame());
    //animations[RUN]->SetPart(15, 18, true); // 걷기
    animations[RUN]->SetPart(19, 22, true); // 빨리달리기

    // JUMP_UP
    animations[JUMP_UP] = new Animation(texture->GetFrame());
    //animations[JUMP_UP]->SetPart(75, 76, true);
    animations[JUMP_UP]->SetPart(0, 0, true);

    // JUMP_DOWN
    animations[JUMP_DOWN] = new Animation(texture->GetFrame());
    animations[JUMP_DOWN]->SetPart(5, 5, true);

    // ROLL
    animations[ROLL] = new Animation(texture->GetFrame());
    animations[ROLL]->SetPart(1, 4);
    animations[ROLL]->SetEndEvent(bind(&ZombieCookie::EndRoll, this));

}
