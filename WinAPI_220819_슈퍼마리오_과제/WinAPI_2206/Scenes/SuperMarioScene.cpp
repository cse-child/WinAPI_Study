#include "Framework.h"
#include "SuperMarioScene.h"

SuperMarioScene::SuperMarioScene()
{
	mario = new Mario();
	marioBg = new MarioBackground();
	enemy = new MarioEnemy();

	BlockManager::Get();

	enemy->Pos().y = WIN_HEIGHT - BlockManager::Get()->GetBlockSize().y - enemy->Size().y*0.5f;
}

SuperMarioScene::~SuperMarioScene()
{
	delete mario;
	delete marioBg;
	delete enemy;

	BlockManager::Delete();
}

void SuperMarioScene::Update()
{
	CollisionMarioAndEnemy();

	mario->Update();
	marioBg->Update();
	enemy->Update();

	BlockManager::Get()->Update();
}

void SuperMarioScene::Render(HDC hdc)
{
	marioBg->Render(hdc);
	enemy->Render(hdc);
	BlockManager::Get()->Render(hdc);

	mario->Render(hdc);
}

void SuperMarioScene::CollisionMarioAndEnemy()
{
	if (!enemy->IsCollision(mario->GetBodyRect())) return;

	// Mario attack to Enemy
	if (mario->Pos().y < enemy->Pos().y)
	{
		enemy->SetAction(MarioEnemy::ActionType::DIE);
		mario->Attack();
		return;
	}

	// Enemy attack to Mario
	mario->SetDie();
}
