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
	Line* barrel; // ����

	/* ���ʺй��� �ƴ� ȣ�������� ���ϱ� */
	// PI / 180 = 1��
	// PI / 6 = 30��
	// PI / 2 = 90��
	// PI = 180��
	float angle = PI / 6;
	float barrelLength = 200;
};