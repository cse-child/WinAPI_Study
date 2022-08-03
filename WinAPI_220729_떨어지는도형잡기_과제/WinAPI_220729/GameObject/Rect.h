#pragma once

class Rect : public Object
{
public:
	Rect(POINT pos, UINT area);
	~Rect();

	virtual void Render(HDC hdc) override;
	virtual bool IsCollision(POINT pos) override;

private:
	UINT area;
};