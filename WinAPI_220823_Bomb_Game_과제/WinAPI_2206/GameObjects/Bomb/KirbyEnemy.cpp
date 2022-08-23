#include "Framework.h"

KirbyEnemy::KirbyEnemy()
{
	Texture* texture = TEXTURE->Add(L"Textures/Enemy.bmp", 52, 42);
	SetTexture(texture);
	isActive = false;
}

KirbyEnemy::~KirbyEnemy()
{
}

void KirbyEnemy::Update()
{
	if (!isActive) return;

	if (!isLand)
		Move();
	else
		PlayerToMove();


}

void KirbyEnemy::Render(HDC hdc)
{
	if (!isActive) return;

	ImageRect::Render(hdc);
}

void KirbyEnemy::Drop()
{
	isActive = true;
	pos.x = Random(Half().x+50.0f, WIN_WIDTH - Half().x-50.0f);
	pos.y = 0;
}

void KirbyEnemy::Move()
{
	pos.y += speed * DELTA;

	float height = landTexture->GetPixelHeight(pos);
	if (Bottom() > height)
	{
		pos.y = height - Half().y;
		isLand = true;
	}
}

void KirbyEnemy::PlayerToMove()
{
	direction = playerPos - pos;
	pos.x += direction.Normalized().x * traceSpeed * DELTA;

	velocity.y -= GRAVITY * DELTA;
	pos.y -= velocity.y * DELTA;

	float height = landTexture->GetPixelHeight(pos);
	if (Bottom() > height)
	{
		pos.y = height - Half().y;
		velocity.y = 0.0f;
	}
}

bool KirbyEnemy::CollisionExplodeCircle(Circle* circle)
{
	if (!isActive) return false;

	if (IsCollision(circle))
		return true;

	return false;
}
