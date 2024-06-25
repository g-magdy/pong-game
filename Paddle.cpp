#include "Paddle.h"

void Paddle::draw()
{
    DrawRectangle(x, y, width, height, color);
}

void Paddle::move()
{
    const int margin = 12;
    if (IsKeyDown(KEY_UP) && y > margin)
        y -= speed;
    if (IsKeyDown(KEY_DOWN) && y < GetScreenHeight() - height - margin)
        y += speed;
}