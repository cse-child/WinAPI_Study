#include "Framework.h"

Mario::Mario()
{
	curType = IDLE_R;
	speed = 300.0f;
	jumpCount = 0;
	isRight = true;
	isDie = false;

	CreateAnimations();

	animations[curType]->Play();

	size *= 1.5f;
	pos = { CENTER_X, CENTER_Y };

	bodyRect = new Rect(Vector2(), { 50, 50 });
	bodyOffset.y = 10;
}

Mario::~Mario()
{
	for (pair<ActionType, Animation*> animation : animations)
		delete animation.second;

	delete bodyRect;
}

void Mario::Update()
{
	Move();
	Jump();
	CollisionBlock();
	CollisionJumpBlock();
	SetAnimation();
	Die();

	animations[curType]->Update();

	pos.y -= velocity.y * DELTA;
	bodyRect->Pos() = pos + bodyOffset;
}

void Mario::Render(HDC hdc)
{
	//bodyRect->Render(hdc);
	ImageRect::Render(hdc, animations[curType]->GetFrame());

	/*wstring str = L"curType : " + to_wstring(curType);
	TextOut(hdc, 0, 60, str.c_str(), str.length());*/
}

void Mario::Attack()
{
	velocity.y = JUMP_POWER * 0.5f;
}

void Mario::Die()
{
	if (!isDie) return;

	if (Top() > WIN_HEIGHT) // 착지
	{
		isActive = false;
		GameManager::Get()->Stop();
		MessageBox(hWnd, L"GameOver", L"GameOver", MB_OK);
		PostQuitMessage(0);
	}
}

void Mario::SetDie()
{
	curType = DIE;
	velocity.y = JUMP_POWER * 0.5f;
	isDie = true;
}

void Mario::Move()
{
	if (KEY_PRESS(VK_RIGHT))
	{
		velocity.x += ACCEL * DELTA;

		if (velocity.x > MAX_VELOCITY)
			velocity.x = MAX_VELOCITY;
	}

	if (KEY_PRESS(VK_LEFT))
	{
		velocity.x -= ACCEL * DELTA;

		if (velocity.x < -MAX_VELOCITY)
			velocity.x = -MAX_VELOCITY;
	}

	velocity.x = Clamp(-MAX_VELOCITY, MAX_VELOCITY, velocity.x);

	velocity.x = LERP(velocity.x, 0.0f, DECEL * DELTA);

	pos.x += velocity.x * DELTA;

	if (velocity.x > 0.0f)
		isRight = true;
	else if (velocity.x < 0.0f)
		isRight = false;

	if (jumpCount > 0) return;
}

void Mario::Jump()
{
	if (jumpCount < MAX_JUMP_COUNT && KEY_DOWN(VK_UP))
	{
		velocity.y = JUMP_POWER;
		jumpCount++;
	}

	velocity.y -= GRAVITY * DELTA;
	//pos.y -= velocity.y * DELTA;

	//if (Bottom() > WIN_HEIGHT) // 착지
	//{
	//	jumpCount = 0;
	//	pos.y = WIN_HEIGHT - Half().y;
	//}
}

void Mario::SetAnimation()
{
	if (isDie) return;

	if (abs(velocity.y > 1.0f)) // 뛰는중 
	{
		if (isRight)
			SetAction(JUMP_R);
		else
			SetAction(JUMP_L);
		return;
	}

	if (velocity.x > 5.0f) // 오른쪽으로 진행중
		SetAction(RUN_R);
	else if (velocity.x < -5.0f) // 왼쪽으로 진행중
		SetAction(RUN_L);
	else
	{
		if (isRight)
			SetAction(IDLE_R);
		else
			SetAction(IDLE_L);
	}
}

void Mario::SetAction(ActionType type)
{
	if (curType == type) return;

	curType = type;
	animations[curType]->Play();
}

void Mario::CollisionBlock()
{
	if (isDie) return;

	Rect* rect = BlockManager::Get()->IsCollision(bodyRect);

	if (rect == nullptr) return;
	if (velocity.y > 0) return;
	if (Bottom() > rect->Pos().y) return;

	velocity.y = 0;
	jumpCount = 0;
}

void Mario::CollisionJumpBlock()
{
	Rect* rect = BlockManager::Get()->IsCollision(bodyRect);

	if (rect == nullptr) return;

	if ((curType == JUMP_L || curType == JUMP_R)
		&& (bodyRect->Top() < rect->Bottom()))
	{
		rect->Active() = false;
		velocity.y = 0;
		jumpCount = 0;
	}
}

void Mario::CreateAnimations()
{
	Texture* texture = TEXTURE->Add(L"Textures/Mario.bmp", 914, 336, 13, 6);

	SetTexture(texture);

	// IDLE
	animations[IDLE_R] = new Animation(texture->GetFrame());
	animations[IDLE_R]->SetPart(0, 0, true);

	animations[IDLE_L] = new Animation(texture->GetFrame());
	animations[IDLE_L]->SetPart(39, 39, true);

	// RUN
	animations[RUN_R] = new Animation(texture->GetFrame());
	animations[RUN_R]->SetPart(0, 2, true);

	animations[RUN_L] = new Animation(texture->GetFrame());
	animations[RUN_L]->SetReversePart(46, 44, true);

	// JUMP
	animations[JUMP_R] = new Animation(texture->GetFrame());
	animations[JUMP_R]->SetPart(19, 19, true);

	animations[JUMP_L] = new Animation(texture->GetFrame());
	animations[JUMP_L]->SetPart(54, 54, true);

	// DIE
	animations[DIE] = new Animation(texture->GetFrame());
	animations[DIE]->SetPart(35, 35, true);
	//animations[DIE]->SetEndEvent(bind(&Mario::EndDie, this));
}
