#include "Framework.h"
#include "StartScene.h"

StartScene::StartScene()
{
	Texture* texture = TEXTURE->Add(L"Textures/BtnNormal.bmp", 256, 64);
	button = new Button(texture);
	//button->SetEvent(bind(&StartScene::ChangeCameraScene, this));

	// placeholders::_1 - 매개변수 개수
	button->SetObjEvent(bind(&StartScene::SelectButton, this, placeholders::_1));
	button->Pos() = { CENTER_X, CENTER_Y };
	
	texture = TEXTURE->Add(L"Textures/BtnOver.bmp", 256, 64);
	button->SetOverTexture(texture);
	texture = TEXTURE->Add(L"Textures/BtnDown.bmp", 256, 64);
	button->SetDownTexture(texture);
	
	HFONT font = CreateFont(40, 0, 0, 0, 1, false, false, false, HANGUL_CHARSET,
		100, 0, 0, 0, L"궁서체");

	button->SetFont(font, 40, BLUE);

	button->SetText("시작");


	button2 = new Button(texture);
	button2->SetObjEvent(bind(&StartScene::SelectButton, this, placeholders::_1));
	button2->Pos() = { CENTER_X, CENTER_Y + 100 };

	texture = TEXTURE->Add(L"Textures/BtnOver.bmp", 256, 64);
	button2->SetOverTexture(texture);
	texture = TEXTURE->Add(L"Textures/BtnDown.bmp", 256, 64);
	button2->SetDownTexture(texture);
	button2->SetFont(font, 40, BLUE);

	button2->SetText("버튼2");

	DataManager::Get();
}

StartScene::~StartScene()
{
	delete button;
}

void StartScene::Update()
{
	button->Update();
}

void StartScene::Render(HDC hdc)
{
	button->Render(hdc);
}

void StartScene::ChangeCameraScene()
{
	SCENE->ChangeScene("Camera");
}

void StartScene::SelectButton(void* obj)
{
	Button* button = (Button*)obj;

	button->SetText("클릭");
}
