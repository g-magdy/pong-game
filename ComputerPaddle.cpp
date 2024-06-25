#include "ComputerPaddle.h"

ComputerPaddle::ComputerPaddle()
{
    currentDirection = 1;
}

void ComputerPaddle::oscillateUpandDown()
{
    const int margin = 12;

    if (y <= margin || y >= GetScreenHeight() - height - margin)
        currentDirection *= -1;

    y += speed * currentDirection;
}

//this method cannot be used in combination with the "Oscillate up and down" method
void ComputerPaddle::trackBall(int ball_y)
{
    const int margin = 12;

    if (ball_y > y + height / 2 && y < GetScreenHeight() - height - margin)
        y += speed;
    else if (ball_y < y + height / 2 && y > margin)
        y -= speed; 
}