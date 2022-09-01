#pragma once

class PipeManager : public Singleton<PipeManager>
{
private:
    const UINT PIPE_NUM = 10;

    const float MIN_PIPE_HEIGHT = -200.0f;
    const float MAX_PIPE_HEIGHT = 100.0f;
public:
    PipeManager();
    ~PipeManager();

    void Update();
    void Render(HDC hdc);

    bool IsCollision(Rect * rect);

private:
    vector<ImageRect *> upPipes;
    vector<ImageRect *> downPipes;

    float speed = 500.0f;

    Vector2 interval = { 400, 400 };
};