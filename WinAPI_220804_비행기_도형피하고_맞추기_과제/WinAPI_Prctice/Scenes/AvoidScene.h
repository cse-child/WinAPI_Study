#pragma once

class AvoidScnene : public Scene
{
public:
	AvoidScnene();
	~AvoidScnene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Plane* plane;
};