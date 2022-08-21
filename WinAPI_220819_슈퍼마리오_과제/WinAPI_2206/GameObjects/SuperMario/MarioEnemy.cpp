#include "Framework.h"

MarioEnemy::MarioEnemy()
{
	CreateAnimations();

	curType = WALK;
	isLeftMove = true;

	pos = { WIN_WIDTH - 100.0f, 0};

	animations[curType]->Play();
}

MarioEnemy::~MarioEnemy()
{
	for (pair<ActionType, Animation*> animation : animations)
		delete animation.second;
}

void MarioEnemy::Update()
{
	Move();

	animations[curType]->Update();
}

void MarioEnemy::Render(HDC hdc)
{
	ImageRect::Render(hdc, animations[curType]->GetFrame());
}

void MarioEnemy::EndDie()
{
	isActive = false;
}

void MarioEnemy::SetAction(ActionType type)
{
	if (curType == type) return;

	curType = type;
	animations[curType]->Play();
}

void MarioEnemy::Move()
{
	if (isLeftMove)
		pos.x -= speed * DELTA;
	else
		pos.x += speed * DELTA;

	if (Left() < 0)
		isLeftMove = false;
	else if (Right() > WIN_WIDTH)
		isLeftMove = true;
}

void MarioEnemy::CreateAnimations()
{
	Texture* texture = TEXTURE->Add(L"Textures/Mario_Enemy.bmp", 222, 72, 3, 1);

	SetTexture(texture);

	// WALK
	animations[WALK] = new Animation(texture->GetFrame());
	animations[WALK]->SetPart(0, 1, true);

	// DIE
	animations[DIE] = new Animation(texture->GetFrame());
	animations[DIE]->SetPart(2,2);
	animations[DIE]->SetEndEvent(bind(&MarioEnemy::EndDie, this));
}