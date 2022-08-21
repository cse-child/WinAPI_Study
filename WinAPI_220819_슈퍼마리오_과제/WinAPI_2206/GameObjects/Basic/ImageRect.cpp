#include "Framework.h"

ImageRect::ImageRect()
{
}

ImageRect::ImageRect(Texture * texture)
    : texture(texture)
{
    size = texture->GetSize();
}

ImageRect::~ImageRect()
{
}

void ImageRect::Render(HDC hdc, POINT curFrame)
{
    if (!isActive) return;

    texture->Render(hdc, this, curFrame);
}

void ImageRect::SetTexture(Texture * texture)
{
    this->texture = texture;
    size = texture->GetSize();
}