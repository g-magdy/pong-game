#pragma once

#include "Paddle.h"

class ComputerPaddle : public Paddle
{
private:
    int currentDirection;

public:
    ComputerPaddle();
    void oscillateUpandDown();
    void trackBall(int ball_y);
};