#pragma once

class FollowCircleScene : public Scene
{
public:
	FollowCircleScene();
	~FollowCircleScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	void CollisionBulletAndFollowCircle();

private:
	Cannon* player;
	//Arrow* player;

};