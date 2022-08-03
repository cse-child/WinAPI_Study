#pragma once

class Circle : public Object
{
public:
	Circle(POINT pos, UINT radius);
	~Circle();

	virtual void Render(HDC hdc) override;

	virtual bool IsCollision(POINT pos) override;

private:
	UINT radius;
};