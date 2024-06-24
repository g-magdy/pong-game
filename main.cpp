/**
 * This game is an intro for me to use raylib
 * comments here are for my understanding .. repetition
 *  */

#include <iostream>
#include "Ball.h"

Ball ball;

int main()
{
    // Basic setup
    const int screenWidth = 1280;
    const int screenHeight = 800;
    // draw initial window
    InitWindow(screenWidth, screenHeight, "Welcome to my game!");

    // this ensures that the following while loop 60 times per second,
    // and not depending on the person's computer
    SetTargetFPS(60);

    // Initialize parameters of objects here

    ball.setParams(screenWidth / 2,
                    screenHeight / 2,
                    18, 5, 5, YELLOW);


    // while the escape button or the X icon have not been clicked
    while (WindowShouldClose() == false)
    {
        // UPDATE OBJECTS HERE
        ball.update();


        // Draw
        // ----------------------------------------------------------------------------
        BeginDrawing();
        //* important to remove old traces of the game
        ClearBackground(BLACK);

        // separating line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        
        ball.drawBall();

        const int rectangeWidth = 20;
        const int rectangleHeight = 120;
        const int margin = 12;

        // first rectangle
        DrawRectangle(margin, screenHeight / 2 - rectangleHeight / 2,
                      rectangeWidth, rectangleHeight, WHITE);

        // second rectange
        DrawRectangle(screenWidth - margin - rectangeWidth, screenHeight / 2 - rectangleHeight / 2,
                      rectangeWidth, rectangleHeight, WHITE);


        EndDrawing();
    }

    // close the window and finish the game
    CloseWindow();
    return 0;
}