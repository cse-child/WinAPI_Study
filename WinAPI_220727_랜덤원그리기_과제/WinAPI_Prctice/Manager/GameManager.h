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

	void SetHWND(HWND hWnd);

	HWND GetHWND() { return hWnd; }

private:
	Scene* scene;

	HWND hWnd;
	HDC hdc;
};