#include "Framework.h"

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::SetEvent(string key, function<void()> Event)
{
	if (Events.count(key) > 0) return;

	Events[key] = Event;
}

void Observer::AddObjEvent(string key, function<void(void*)> Event)
{
	ObjEvents[key].push_back(Event);
}

void Observer::ExcuteEvent(string key)
{
	if (Events.count(key) == 0) return;

	Events[key]();
}

void Observer::ExcuteEvents(string key, void* obj)
{
	for (function<void(void*)> Event : ObjEvents[key])
	{
		Event(obj);
	}
}
