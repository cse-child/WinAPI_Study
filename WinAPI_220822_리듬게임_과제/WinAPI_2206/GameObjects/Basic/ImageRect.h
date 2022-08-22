#pragma once

class ImageRect : public Rect
{
public:
    ImageRect();
    ImageRect(Texture * texture);
    ~ImageRect();

    void Render(HDC hdc, POINT curFrame = { 0, 0 });

    void SetTexture(Texture * texture);
protected:
    Texture * texture;
};