#pragma once

class PlaneScene : public Scene
{
public:
	PlaneScene();
	~PlaneScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	POINT GetPos() { return pos; }

private:
	void Move();
	void CreateBody();

private:
	POINT pos;
	vector<Rect*> bodyRect;

	Rect* leftWingRect;
	Rect* rightWingRect;

	HBRUSH brush;

};