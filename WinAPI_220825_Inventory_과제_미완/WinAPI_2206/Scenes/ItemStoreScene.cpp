#include "Framework.h"
#include "ItemStoreScene.h"


ItemStoreScene::ItemStoreScene()
{
	CreateButton();

	//ItemDataManager::Get()->SetItemStoreScene(this);
}

ItemStoreScene::~ItemStoreScene()
{
	ItemDataManager::Delete();
	delete button;
}

void ItemStoreScene::Update()
{
	ItemDataManager::Get()->Update();
	button->Update();
}

void ItemStoreScene::Render(HDC hdc)
{
	ItemDataManager::Get()->Render(hdc);
	button->Render(hdc);	
}

//void ItemStoreScene::BuyItem(void* obj)
//{
//	Item* item = (Item*)obj;
//	
//	item->Active() = false;
//}

void ItemStoreScene::CreateButton()
{
	Texture* buttonTexture = TEXTURE->Add(L"Textures/BtnNormal.bmp", 256, 64);
	button = new Button(buttonTexture);
	//button->SetObjEvent(bind(&ItemStoreScene::BuyItem, this, placeholders::_1));

	button->Pos() = { CENTER_X * 0.8f, WIN_HEIGHT * 0.9f };

	buttonTexture = TEXTURE->Add(L"Textures/BtnOver.bmp", 256, 64);
	button->SetOverTexture(buttonTexture);
	buttonTexture = TEXTURE->Add(L"Textures/BtnDown.bmp", 256, 64);
	button->SetDownTexture(buttonTexture);

	HFONT font = CreateFont(40, 0, 0, 0, 1, false, false, false, HANGUL_CHARSET, 100, 0, 0, 0, L"±Ã¼­Ã¼");
	button->SetFont(font, 40, BLUE);
	button->SetText("±¸¸Å");
}
