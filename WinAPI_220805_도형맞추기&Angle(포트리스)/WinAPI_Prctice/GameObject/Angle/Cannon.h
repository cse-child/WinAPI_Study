#pragma once

class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

private:
	Circle* body;
	Line* barrel; // 포신

	/* 육십분법이 아닌 호도법으로 구하기 */
	// PI / 180 = 1도
	// PI / 6 = 30도
	// PI / 2 = 90도
	// PI = 180도
	float angle = PI / 6;
	float barrelLength = 200;
};