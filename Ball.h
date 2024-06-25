#pragma once
#include <raylib.h>

class Ball
{    
public:
    int x, y;
    int initialSpeed;
    int speed_x, speed_y;
    int radius;
    Color color;
    Ball();
    void setParams(int x, int y, int radius, int speed_x, int speed_y, Color clr);
    ~Ball();

    void drawBall();
    void move();
    void checkCollisionWithPaddle(float paddle_x, float paddle_y, float paddle_width, float paddle_height);
    void reCentre(int x_dir);
};