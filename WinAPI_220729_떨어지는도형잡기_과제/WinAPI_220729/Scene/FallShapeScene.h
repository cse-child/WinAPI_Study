#pragma once

class FallShapeScene : public Scene
{
private:
	const UINT POOLING_SIZE = 20;

public:
	FallShapeScene();
	~FallShapeScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};