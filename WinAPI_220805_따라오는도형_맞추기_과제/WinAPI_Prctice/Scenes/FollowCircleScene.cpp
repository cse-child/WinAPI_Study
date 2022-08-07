#include "Framework.h"
#include "FollowCircleScene.h"

FollowCircleScene::FollowCircleScene()
{
	FollowManager::Get()->CreateCircles(10);
	player = new Cannon();
	//player = new Arrow();
}

FollowCircleScene::~FollowCircleScene()
{
	FollowManager::Get()->Delete();
	delete player;
}

void FollowCircleScene::Update()
{
	player->Update();
	FollowManager::Get()->SetPlayerPos(player->GetPlayerPos());
	FollowManager::Get()->Update();
	CollisionBulletAndFollowCircle();
}

void FollowCircleScene::Render(HDC hdc)
{
	player->Render(hdc);
	FollowManager::Get()->Render(hdc);

	wstring str = L"10개 이상 파괴하면 게임 클리어!";
	TextOut(hdc, CENTER_X, 0, str.c_str(), (int)str.length());
}

void FollowCircleScene::CollisionBulletAndFollowCircle()
{
	for (Bullet* bullet : BulletManager::Get()->GetBullets())
	{
		if (!bullet->Active()) continue;

		if (FollowManager::Get()->IsCollision(bullet))
		{
			bullet->Active() = false;
			BulletManager::Get()->IncreaseCount();
		}
	}
}
