#include "Framework.h"
#include "AvoidScene.h"

AvoidScnene::AvoidScnene()
{
	plane = new Plane();
	DropManager::Get()->CreateCircles(50);
	BulletManager::Get()->CreateBullets(50);
}

AvoidScnene::~AvoidScnene()
{
	delete plane;
	DropManager::Get()->Delete();
	BulletManager::Get()->Delete();
}

void AvoidScnene::Update()
{
	plane->Update();
	DropManager::Get()->Update();
	BulletManager::Get()->Update();
	plane->PlaneCollision();
}

void AvoidScnene::Render(HDC hdc)
{
	plane->Render(hdc);
	DropManager::Get()->Render(hdc);
	BulletManager::Get()->Render(hdc);
}
