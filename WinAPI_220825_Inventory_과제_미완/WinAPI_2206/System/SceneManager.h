#pragma once

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Update();
	void Render(HDC hdc);

	void Add(string key, Scene* scene);
	
	Scene* GetScene(string key);

	void ChangeScene(string key);

private:
	unordered_map<string, Scene*> scenes;

	Scene* curScene = nullptr;
};