#pragma once

class GameManager : public Singleton<GameManager>
{
private:
	friend class Singleton;

	GameManager();
	~GameManager();

public:
	void Update();
	void Render();

	void SetInit(HWND hWnd);

	HWND GetHWND() { return hWnd; }

	void Stop() { isStop = true; }
	void Play() { isStop = false; }

private:
	Scene* scene;

	HDC hdc;
	HWND hWnd;

	HDC backBuffer;
	HBITMAP bitmap;

	bool isStop = false;
};