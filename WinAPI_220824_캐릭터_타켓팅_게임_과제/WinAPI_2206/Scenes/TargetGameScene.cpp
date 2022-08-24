#include "Framework.h"
#include "TargetGameScene.h"

TargetGameScene::TargetGameScene()
{
	Texture* mapT = TEXTURE->Add(L"Textures/WideMap.bmp", 4358, 876);
	land = new ImageRect(mapT);
	land->Pos() += land->Half();

	Texture* doorT = TEXTURE->Add(L"Textures/door.bmp", 108, 204);
	door = new ImageRect(doorT);
	door->Pos() = { mapT->GetSize().x - doorT->GetSize().x*0.5f, CENTER_Y - 130.0f};

	zzanggu = new ZzangGu();
	zzanggu->SetLand(land->GetTexture());

	mom = new ZzangGuMom();
	mom->SetLand(land->GetTexture());
	mom->Pos().x = zzanggu->Pos().x - 100.0f;

	bg = new Background();

	isChange = false;

	Camera::Get()->SetMapRect(land);
	Camera::Get()->SetTartget(zzanggu);
}

TargetGameScene::~TargetGameScene()
{
	delete land;
	delete door;
	delete zzanggu;
	delete mom;
	delete bg;
}

void TargetGameScene::Update()
{
	if(!isChange)
		zzanggu->Update();
	else
		mom->Update();

	bg->Update();

	ChangeCharacter();
	ReStart();
	CollisionPlayerAndDoor();
}

void TargetGameScene::Render(HDC hdc)
{
	bg->Render(hdc);
	land->CamRender(hdc);
	door->CamRender(hdc);
	zzanggu->Render(hdc);
	mom->Render(hdc);
}

void TargetGameScene::ChangeCharacter()
{
	if (KEY_DOWN(VK_SPACE))
	{
		if (!isChange)
		{
			if (!mom->Active()) return;
			Camera::Get()->SetTartget(mom);
			isChange = true;
		}
		else
		{
			if (!zzanggu->Active()) return;
			Camera::Get()->SetTartget(zzanggu);
			isChange = false;
		}
	}
}

void TargetGameScene::ReStart()
{
	if (KEY_DOWN('R'))
	{
		isChange = false;
		zzanggu->Active() = true;
		mom->Active() = true;
		zzanggu->Pos() = { CENTER_X, CENTER_Y };
		mom->Pos() = { zzanggu->Pos().x - 100.0f, CENTER_Y + 30.0f };
		Camera::Get()->SetTartget(zzanggu);
	}
}

void TargetGameScene::CollisionPlayerAndDoor()
{
	if (zzanggu->IsCollision(door))
	{
		zzanggu->Active() = false;
		if (mom->Active())
		{
			Camera::Get()->SetTartget(mom);
			isChange = true;
		}
		else
			End();
	}

	if (mom->IsCollision(door))
	{
		mom->Active() = false;
		if (zzanggu->Active())
		{
			Camera::Get()->SetTartget(zzanggu);
			isChange = false;
		}
		else
			End();
	}
}

void TargetGameScene::End()
{
	MessageBox(hWnd, L"Game Clear !", L"Game Clear", MB_OK);

	PostQuitMessage(0);
}
