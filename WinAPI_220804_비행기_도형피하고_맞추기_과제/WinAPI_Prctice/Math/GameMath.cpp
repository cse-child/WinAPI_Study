#include "Framework.h"

int GameMath::Random(const int& min, const int& max)
{
    return rand() % (max - min) + min;
}

UINT GameMath::Random(const UINT& min, const UINT& max)
{
    return rand() % (max - min) + min;
}

float GameMath::Random(const float& min, const float& max)
{
    float normal = rand() / (float)RAND_MAX;

    return (max - min) * normal + min;
}

int GameMath::Distance(const POINT& x, const POINT& y)
{
    int distance = sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
    return distance;
}

float GameMath::Distance(const Vector2& x, const Vector2& y)
{
    float distance = sqrtf(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
    return distance;
}
