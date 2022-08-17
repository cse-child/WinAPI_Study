#pragma once

class Animation
{
public:
	Animation(POINT imageFrame, float frameUpdateTime = 0.1f);
	~Animation();

	void Update();

	void SetDefault(bool loop = false, bool pingpong = false);
	void SetArray(int* arr, int arrSize, bool loop = false, bool pingpong = false);
	void SetPart(int start, int end, bool loop = false, bool pingpong = false);
	
	void SetPingpong();

	void Play() { isPlay = true, curPlayNum = 0; }
	void Stop();

	bool IsPlay() { return isPlay; }

	POINT GetFrame() { return frames[action[curPlayNum]]; }

private:
	vector<POINT> frames;
	vector<int> action;

	int curPlayNum = 0;

	POINT imageFrame;

	bool isPlay = false;
	bool isLoop = false;

	float time = 0.0f;
	float frameUpdateTime;


};