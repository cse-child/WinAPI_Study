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

	void SetInit();

	void Stop() { isStop = true; }
	void Play() { isStop = false; }

private:
	void Create();
	void Delete();

private:
	Scene* scene = nullptr;

	HDC hdc = nullptr;

	HDC backBuffer = nullptr;
	HBITMAP bitmap = nullptr;

	bool isStop = false;
};