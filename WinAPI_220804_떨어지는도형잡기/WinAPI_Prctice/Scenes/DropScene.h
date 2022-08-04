#pragma once

#include "GameObject/DropCircle.h"
#include "GameObject/DropManager.h"

class DropScene : public Scene
{
public:
	DropScene();
	~DropScene();
	
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//DropCircle* dropCircle;

};