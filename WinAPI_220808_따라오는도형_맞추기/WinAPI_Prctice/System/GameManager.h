#pragma once

class GameManager : public Singleton<GameManager>
{
private:
	// private�� GameManager�� Singleton���� ����� �� ����
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
	Scene* scene = nullptr;

	HWND hWnd = nullptr;
	HDC hdc = nullptr;

	HDC backBuffer = nullptr;
	HBITMAP bitmap = nullptr;

	bool isStop = false;
};