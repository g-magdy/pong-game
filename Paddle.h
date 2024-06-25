#pragma once
#include <raylib.h>

class Paddle 
{
public:
    int x, y;
    int width, height;
    int speed;
    Color color;

    void draw();
    void move();
};