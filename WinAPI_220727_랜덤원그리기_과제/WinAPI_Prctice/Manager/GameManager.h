#pragma once

class GameManager : public Singleton<GameManager>
{
private:
	// private인 GameManager를 Singleton에서 사용할 수 있음
	friend class Singleton; 

	GameManager();
	~GameManager();

public:
	void Update();
	void Render();

	void SetHWND(HWND hWnd);

	HWND GetHWND() { return hWnd; }

private:
	Scene* scene;

	HWND hWnd;
	HDC hdc;
};