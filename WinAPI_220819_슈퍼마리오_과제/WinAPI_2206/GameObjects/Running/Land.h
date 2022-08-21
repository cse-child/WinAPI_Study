#pragma once

class Land : public ImageRect
{
public:
	Land();
	~Land();

	void Update();

private:
	float speed = 100.0f;

};