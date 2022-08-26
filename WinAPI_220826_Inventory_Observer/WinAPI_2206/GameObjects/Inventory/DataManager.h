#pragma once

struct ItemData
{
	int key;
	string name;
	int price;
	int value;
	POINT imageFrame;
};

class DataManager : public Singleton<DataManager>
{
public:
	DataManager();
	~DataManager();

	map<int, ItemData> GetItemDatas() { return itemDatas; }

private:
	void LoadItemTable();

	void SplitString(string origin, string tok, vector<string>& result);
	void Replace(string& origin, string comp, string rep);
private:
	map<int, ItemData> itemDatas;
};