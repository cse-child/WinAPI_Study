#pragma once

class SuperMarioScene : public Scene
{
public:
	SuperMarioScene();
	~SuperMarioScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void CollisionMarioAndEnemy();

private:
	Mario* mario;

	MarioBackground* marioBg;

	MarioEnemy* enemy;

};