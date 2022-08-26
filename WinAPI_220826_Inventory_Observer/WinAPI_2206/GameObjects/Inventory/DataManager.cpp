#include "Framework.h"

DataManager::DataManager()
{
	LoadItemTable();
}

DataManager::~DataManager()
{
}

void DataManager::LoadItemTable()
{
	// csv 파일 읽기
	FILE* file;
	fopen_s(&file, "TextData/ItemTable.csv", "r");

	bool isFirstLine = true;

	while (true)
	{
		char temp[1024];
		fgets(temp, 1024, file);

		if (isFirstLine)
		{
			isFirstLine = false;
			continue;
		}

		string str = temp;
		Replace(str, "\n", "");

		vector<string> table;
		SplitString(str, ",", table);

		ItemData data;
		data.key = stoi(table[0]);
		data.name = table[1];
		data.price = stoi(table[2]);
		data.value = stoi(table[3]);
		data.imageFrame = { stoi(table[4]), stoi(table[5]) };

		itemDatas[data.key] = data;

		if (feof(file))
			return;
	}
}

void DataManager::SplitString(string origin, string tok, vector<string>& result)
{
	size_t cutAt = 0;

	while ((cutAt = origin.find_first_of(tok)) != origin.npos)
	{
		if (cutAt > 0)
			result.push_back(origin.substr(0, cutAt));

		origin = origin.substr(cutAt + tok.length());
	}
	result.push_back(origin);
}

void DataManager::Replace(string& origin, string comp, string rep)
{
	size_t at = 0;
	while ((at = origin.find(comp, at)) != string::npos)
	{
		origin.replace(at, comp.length(), rep);
		at += rep.length();
	}
}
