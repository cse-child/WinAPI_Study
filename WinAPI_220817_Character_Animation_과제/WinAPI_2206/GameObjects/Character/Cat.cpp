#include "Framework.h"

Cat::Cat()
{
	idleTexture = TEXTURE->Add(L"Textures/Cat_Idle.bmp", 252, 96, 4, 1);
	walkTexture = TEXTURE->Add(L"Textures/Cat_Walk.bmp", 504, 96, 8, 1);
	jumpTexture = TEXTURE->Add(L"Textures/Cat_Jump.bmp", 600, 96, 8, 1);
	kickTexture = TEXTURE->Add(L"Textures/Cat_Kick.bmp", 96, 576, 1, 6);

	curType = IDLE;
	SetTexture(idleTexture);

	CreateAnimation();

	Init();
	
	animations[curType]->Play();
}

Cat::~Cat()
{
	for (pair<ActionType, Animation*> animation : animations)
		delete animation.second;

	TEXTURE->Delete();
}

void Cat::Update()
{
	if (!isActive) return;

	Idle();
	Move();
	Jump();
	Kick();

	animations[curType]->Update();
}

void Cat::Render(HDC hdc)
{
	if (!isActive) return;

	texture->Render(hdc, this, animations[curType]->GetFrame());
}

void Cat::Init()
{
	isActive = true;
	pos = { CENTER_X, CENTER_Y };
	size = texture->GetSize();
}

void Cat::Idle()
{
	if (!isMove && !isJump && !isKick)
	{
		curType = IDLE;
		SetTexture(idleTexture);
	}
}

void Cat::Move()
{
	// walk 만 true, 나머진 false
	if (KEY_DOWN(VK_RIGHT) || KEY_DOWN(VK_LEFT) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_DOWN))
	{
		isMove = true;
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		pos.x += speed * DELTA;
		isMove = true;
	}
	if (KEY_PRESS(VK_LEFT))
	{
		pos.x -= speed * DELTA;
		isMove = true;
	}
	if (KEY_PRESS(VK_UP))
	{
		pos.y -= speed * DELTA;
		isMove = true;
	}
	if (KEY_PRESS(VK_DOWN)) {
		pos.y += speed * DELTA;
		isMove = true;
	}
	// idle만 true, 나머지 false
	if (KEY_UP(VK_RIGHT) || KEY_UP(VK_LEFT) || KEY_UP(VK_UP) || KEY_UP(VK_DOWN))
	{
		isMove = false;
	}

	if (isMove && !isJump && !isKick && curType != WALK)
	{
		curType = WALK;
		SetTexture(walkTexture);
		animations[curType]->Play();
	}
}

void Cat::Jump()
{
	if (KEY_DOWN(VK_SPACE))
	{
		curType = JUMP;
		SetTexture(jumpTexture);
		animations[curType]->Play();
		isJump = true;

		jumpVelocity = JUMP_POWER; // 500
	}

	if (isJump)
	{
		jumpVelocity -= GRAVITY * DELTA; // 980
		pos.y -= jumpVelocity * DELTA;

		if (!animations[curType]->IsPlay())
		{
			isJump = false;
		}
	}
}

void Cat::Kick()
{
	if (KEY_DOWN(VK_CONTROL))
	{
		curType = KICK;
		SetTexture(kickTexture);
		animations[curType]->Play();
		isKick = true;
	}

	if (isKick)
	{
		if (!animations[curType]->IsPlay())
		{
			isKick = false;
		}
	}
}

void Cat::CreateAnimation()
{
	{
		// IDLE
		animations[IDLE] = new Animation(idleTexture->GetFrame());
		animations[IDLE]->SetDefault(true);
	}
	{
		// WALK
		animations[WALK] = new Animation(walkTexture->GetFrame());
		animations[WALK]->SetDefault(true);
	}
	{
		// JUMP
		animations[JUMP] = new Animation(jumpTexture->GetFrame());
		animations[JUMP]->SetDefault();
	}
	{
		// KICK
		animations[KICK] = new Animation(kickTexture->GetFrame());
		animations[KICK]->SetDefault();
	}
}
