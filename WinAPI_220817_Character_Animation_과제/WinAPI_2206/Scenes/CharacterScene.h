#pragma once

class CharacterScene : public Scene
{
public:
	CharacterScene();
	~CharacterScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Cat* character;
};