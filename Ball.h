#pragma once
#include <raylib.h>

class Ball
{    
public:
    int x, y;
    int speed_x, speed_y;
    int radius;
    CLITERAL(Color) color;
    Ball();
    void setParams(int x, int y, int radius, int speed_x, int speed_y, CLITERAL(Color) clr);
    ~Ball();

    void drawBall();
    void update();
    //
};