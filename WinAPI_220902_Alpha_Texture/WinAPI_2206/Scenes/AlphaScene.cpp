#include "Framework.h"
#include "AlphaScene.h"

AlphaScene::AlphaScene()
{
	test = new ImageRect(TEXTURE->Add(L"Textures/test.bmp", 569, 512));
	test->Pos() = { CENTER_X, CENTER_Y };

	cat = new ImageRect(TEXTURE->Add(L"Textures/Cat.bmp", 949, 474, 7, 4));
	cat->Pos() = { CENTER_X, CENTER_Y };
}

AlphaScene::~AlphaScene()
{
	delete test;
	delete cat;
}

void AlphaScene::Update()
{
	alpha += speed * DELTA;

	if (alpha > 255.0f)
	{
		alpha = 255.0;
		speed *= -1.0f;
	}
	else if(alpha < 0.0f)
	{
		alpha = 0.0f;
		speed *= -1.0f;
	}
}

void AlphaScene::Render(HDC hdc)
{
	test->Render(hdc);
	cat->Render(hdc, (int)alpha);
}
