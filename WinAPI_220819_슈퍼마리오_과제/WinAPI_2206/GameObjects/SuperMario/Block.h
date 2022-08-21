#pragma once

class Block : public ImageRect
{
public:
	Block();
	~Block();

	void Update();

private:
	float speed = 100.0f;
};