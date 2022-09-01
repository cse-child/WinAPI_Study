#pragma once

class InventoryScene : public Scene
{
public:
	InventoryScene();
	~InventoryScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Store* store;
	Inventory* inventory;
};