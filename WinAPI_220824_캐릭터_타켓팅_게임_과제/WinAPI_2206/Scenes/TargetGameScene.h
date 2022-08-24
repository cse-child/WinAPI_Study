#pragma once

class TargetGameScene : public Scene
{
public:
	TargetGameScene();
	~TargetGameScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:
	void ChangeCharacter();

	void ReStart();

	void CollisionPlayerAndDoor();

	void End();

private:
	ImageRect* land;
	ImageRect* door;

	Background* bg;

	ZzangGu* zzanggu;

	ZzangGuMom* mom;

	bool isChange;
};