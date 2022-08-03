#pragma once

class Object
{
public:
	Object();
	~Object();

	void Update();
	virtual void Render(HDC hdc) = 0;
	virtual bool IsCollision(POINT pos) = 0;

	POINT& GetPos() { return pos; }

	bool& IsActive() { return isActive; }

	void Fall(POINT pos);
	void SetBrush(HBRUSH brush) { this->brush = brush; }
	void SetSpeed(UINT speed) { this->speed = speed; }

protected:
	POINT pos;
	bool isActive;
	HBRUSH brush;
	UINT speed;
};