#pragma once

class Observer : public Singleton<Observer>
{
public:
	Observer();
	~Observer();

	void SetEvent(string key, function<void()> Event);
	void AddObjEvent(string key, function<void(void*)> Event);

	void ExcuteEvent(string key);
	void ExcuteEvents(string key, void* obj);

private:
	map<string, function<void()>> Events;
	map<string, vector<function<void(void*)>>> ObjEvents;
};