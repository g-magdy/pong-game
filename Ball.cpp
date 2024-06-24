#include "Ball.h"

Ball::Ball() {

}

void Ball::setParams(int x, int y, int radius, int speed_x, int speed_y, CLITERAL(Color) color) {
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

void Ball::update() 
{
    x += speed_x;
    y += speed_y;
}