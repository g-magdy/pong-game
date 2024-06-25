#include "Ball.h"

Ball::Ball() {

}

void Ball::setParams(int x, int y, int radius, int speed_x, int speed_y, Color color) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speed_x = speed_x;
    this-> speed_y = speed_y;
    this->color = color;
}

Ball::~Ball() {

}

void Ball::drawBall()
{
    DrawCircle(x, y, radius, color);
}

void Ball::move() 
{
    x += speed_x;
    y += speed_y;

    if (x >= GetScreenWidth() - radius || x < radius)
        speed_x *= -1;
    if (y >= GetScreenHeight() - radius || y < radius)
        speed_y *= -1;
}