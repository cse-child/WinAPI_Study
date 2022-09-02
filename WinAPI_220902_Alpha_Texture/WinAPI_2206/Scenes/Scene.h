#pragma once

class Scene
{
public:
    virtual ~Scene() = default; // {} 와 같은 문법

    virtual void Update() = 0;
    virtual void LateUpdate() {}
    virtual void Render(HDC hdc) = 0;

    virtual void Start() {}
    virtual void End() {}
};