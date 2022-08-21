#include "Framework.h"

Block::Block()
{
	SetTexture(TEXTURE->Add(L"Textures/Block.bmp", 48, 48));
}

Block::~Block()
{
}

void Block::Update()
{
}
