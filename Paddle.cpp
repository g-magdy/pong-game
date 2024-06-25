#include "Paddle.h"

void Paddle::draw()
{
    DrawRectangleRounded(Rectangle{(float)x, (float)y, (float)width, (float)height},
                         0.5, 0, color);
}

void Paddle::move()
{
    const int margin = 12;
    if (IsKeyDown(KEY_UP) && y > margin)
        y -= speed;
    if (IsKeyDown(KEY_DOWN) && y < GetScreenHeight() - height - margin)
        y += speed;
}