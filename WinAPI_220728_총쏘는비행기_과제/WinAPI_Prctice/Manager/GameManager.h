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

	void SetInit(HWND hWnd);

	HWND GetHWND() { return hWnd; }

private:
	Scene* scene;
	Scene* bulletScene;

	HWND hWnd;
	HDC hdc;

	HDC backBuffer;
	HBITMAP bitmap;
};