#pragma once
class RhythmGameScene : public Scene
{
public:
	RhythmGameScene();
	~RhythmGameScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	void CollisionBeat();
	void Effect();

private:
	Vector2 effectOffset = { 0, 50 };

	NoteBeat::BeatType curType = NoteBeat::NONE;

	UINT score = 0;

};