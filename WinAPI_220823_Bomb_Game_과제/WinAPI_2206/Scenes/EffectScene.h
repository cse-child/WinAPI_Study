#pragma once

class EffectScene : public Scene
{
public:
	EffectScene();
	~EffectScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//Effect* effect;
	FMOD::System* soundSystem;
	FMOD::Sound* sound;
	FMOD::Channel* channel;
};