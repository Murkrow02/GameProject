#pragma once

class GameObject
{
public:
    virtual void DoFrame() = 0;
    virtual void Draw() = 0;
};