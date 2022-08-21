#pragma once

class LandManager : public Singleton<LandManager>
{
public:
	LandManager();
	~LandManager();

	void Update();
	void Render(HDC hdc);
	
	Rect* IsCollision(Rect* rect);

private:
	vector<Land*> lands;

};