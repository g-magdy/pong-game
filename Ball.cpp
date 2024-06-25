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
    {
        speed_x *= -1;
    }

    if (y >= GetScreenHeight() - radius || y < radius)
        speed_y *= -1;
}

void Ball::checkCollisionWithPaddle(float paddle_x, float paddle_y, float paddle_width, float paddle_height)
{
    if (CheckCollisionCircleRec(
        Vector2{(float)x, (float)y},radius,
        Rectangle{paddle_x, paddle_y, paddle_width, paddle_height}
    ))
        speed_x *= -1.1;
}

void Ball::reCentre(int x_dir)
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    speed_x = initialSpeed;
    speed_y = initialSpeed;
    
    // reflect towards the left (if x_dir is zero then the player scored)
    if (x_dir == 0)
        speed_x *= -1;

    if (GetRandomValue(0, 1))
        speed_y *= -1;
}