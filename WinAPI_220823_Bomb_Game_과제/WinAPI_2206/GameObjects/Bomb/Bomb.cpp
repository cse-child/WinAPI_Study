#include "Framework.h"

Bomb::Bomb(HBRUSH brush, HPEN pen)
	:hBrush(brush), hPen(pen)
{
	Texture* texture = TEXTURE->Add(L"Textures/Bomb.bmp", 48, 48);
	SetTexture(texture);
	isActive = false;

	bombTime = 3.0f;
	bombUpSize = 40.0f;
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	if (!isActive) return;

	playTime += DELTA;

	if (playTime > bombTime)
	{
		if (isPlant)
			BombExplode();
		playTime = 0.0f;
	}
	Move();	
}

void Bomb::Render(HDC hdc)
{
	if (!isActive) return;
	if (!isPlant) return;

	ImageRect::Render(hdc);
}

void Bomb::PlantBomb()
{
	isActive = true;
	isPlant = true;
	playTime = 0.0f;
}

void Bomb::Move()
{
	velocity.y -= GRAVITY * DELTA;
	pos.y -= velocity.y * DELTA;

	float height = landTexture->GetPixelHeight(pos);
	
	if (Bottom() > height)
	{
		velocity.y = 0.0f;
		pos.y = height - Half().y;
	}
}

void Bomb::BombExplode()
{
	if (isPlant)
	{
		Audio::Get()->Play("bomb");
		EffectManager::Get()->Play("bomb", pos);
		isActive = false;
		isPlant = false;
		DeleteLand();
	}
}

void Bomb::DeleteLand()
{
	SelectObject(landTexture->GetMemDC(), hBrush);
	SelectObject(landTexture->GetMemDC(), hPen);
	
	Ellipse(landTexture->GetMemDC(),
		(int)Left()- bombUpSize, (int)Top()- bombUpSize,
		(int)Right()+ bombUpSize, (int)Bottom()+ bombUpSize);
}

Vector2 Bomb::GetExplodeSize()
{
	return { pos.x - bombUpSize , pos.y + bombUpSize };
}

Circle* Bomb::GetExplodeCircle()
{
	if (isPlant)
	{
		float radius = (Left() - bombUpSize) + (Right() + bombUpSize) * 0.5;
		Vector2 explodePos = { pos.x - bombUpSize , pos.y + bombUpSize };
		Circle* circle = new Circle(explodePos, radius);
		return circle;
	}
	else
		return nullptr;
	
}