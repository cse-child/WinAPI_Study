#include "Framework.h"

ZzangGuMom::ZzangGuMom()
{
	CreateAnimations();

	pos = { CENTER_X, CENTER_Y +30.0f};

	curType = IDLE_R;
	animations[curType]->Play();
}

ZzangGuMom::~ZzangGuMom()
{
	for (pair<ActionType, Animation*> animation : animations)
		delete animation.second;
	animations.clear();
}

void ZzangGuMom::Update()
{
	Move();
	Jump();
	SetAnimation();

	animations[curType]->Update();
}

void ZzangGuMom::Render(HDC hdc)
{
	ImageRect::CamRender(hdc, animations[curType]->GetFrame());
}

bool ZzangGuMom::CanMove()
{
	Vector2 tempPos = pos;
	float nextHeight = 0.0f;

	if (isRight)
	{
		tempPos.x = Right();
	}
	else
	{
		tempPos.x = Left();
	}

	nextHeight = landTexture->GetPixelHeight(tempPos);

	if (Bottom() - nextHeight > SLOPE)
		return false;

	return true;
}

void ZzangGuMom::Move()
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

		if (velocity.x < -MAX_VELOCITY)
			velocity.x = -MAX_VELOCITY;
	}

	velocity.x = Clamp(-MAX_VELOCITY, MAX_VELOCITY, velocity.x);
	velocity.x = LERP(velocity.x, 0.0f, DECEL * DELTA);

	if (CanMove())
		pos.x += velocity.x * DELTA;

	if (velocity.x > 0.0f)
		isRight = true;
	else if (velocity.x < 0.0f)
		isRight = false;

	if (Left() < 0.0f)
		pos.x = Half().x;

	if (Right() > landTexture->GetSize().x)
		pos.x = landTexture->GetSize().x - Half().x;
}

void ZzangGuMom::Jump()
{
	if (jumpCount < MAX_JUMP_COUNT && KEY_DOWN(VK_UP))
	{
		velocity.y = JUMP_POWER;
		jumpCount++;
	}

	velocity.y -= GRAVITY * DELTA;
	pos.y -= velocity.y * DELTA;

	height = landTexture->GetPixelHeight(pos);

	if (Bottom() > height)
	{
		jumpCount = 0;
		pos.y = height - Half().y;
		velocity.y = 0;
	}
}

void ZzangGuMom::SetAnimation()
{
	if (abs(velocity.y) > 1.0f)
	{
		if (isRight)
			SetAction(JUMP_R);
		else
			SetAction(JUMP_L);
		return;
	}

	if (velocity.x > 5.0f)
		SetAction(WALK_R);
	else if (velocity.x < -5.0f)
		SetAction(WALK_L);
	else
	{
		if (isRight)
			SetAction(IDLE_R);
		else
			SetAction(IDLE_L);
	}
}

void ZzangGuMom::SetAction(ActionType type)
{
	if (curType == type) return;

	curType = type;
	animations[curType]->Play();
}

void ZzangGuMom::CreateAnimations()
{
	Texture* texture = TEXTURE->Add(L"Textures/ZzangGuMom.bmp", 1452, 384, 11, 2);
	SetTexture(texture);

	// IDLE
	animations[IDLE_R] = new Animation(texture->GetFrame());
	animations[IDLE_R]->SetPart(0, 0, true);
	animations[IDLE_L] = new Animation(texture->GetFrame());
	animations[IDLE_L]->SetPart(21, 21, true);

	// WALK
	animations[WALK_R] = new Animation(texture->GetFrame());
	animations[WALK_R]->SetPart(1, 10, true);
	animations[WALK_L] = new Animation(texture->GetFrame());
	animations[WALK_L]->SetReversePart(20, 11, true);

	// JUMP
	animations[JUMP_R] = new Animation(texture->GetFrame());
	animations[JUMP_R]->SetPart(3, 3);
	animations[JUMP_L] = new Animation(texture->GetFrame());
	animations[JUMP_L]->SetReversePart(13, 13);
}
