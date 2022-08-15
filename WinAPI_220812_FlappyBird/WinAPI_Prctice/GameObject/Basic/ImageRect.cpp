#include "Framework.h"

ImageRect::ImageRect()
{
}

ImageRect::ImageRect(Texture* texture)
	:texture(texture)
{
	size = texture->GetSize();
}

ImageRect::~ImageRect()
{
	delete texture;
}

void ImageRect::Render(HDC hdc, POINT curFrame)
{
	if (!isActive) return;

	texture->Render(hdc, this, curFrame);
}
