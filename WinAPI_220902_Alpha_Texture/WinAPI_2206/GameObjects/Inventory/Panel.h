#pragma once

class Panel : public ImageRect
{
public:
	Panel(Texture* texture);
	~Panel();

	void Render(HDC hdc);

protected:
	void Drag();

	bool IsButtonOver();

protected:
	vector<Item*> items;

private:
	Vector2 offset;
	bool isDrag;
};