/**
 * This game is an intro for me to use raylib
 * comments here are for my understanding .. repetition
 *  */

#include <iostream>
#include "Ball.h"
#include "Paddle.h"

Ball ball;
Paddle player1;
Paddle player2;

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
    
    // Ball prameters
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.radius = 10;
    ball.speed_x = 10;
    ball.speed_y = 10;
    ball.color = YELLOW;

    // margin between paddle and edge of screen
    const int margin = 12;

    // Player1 parameters
    player1.width = 20;
    player1.height = 120;
    player1.color = WHITE;
    player1.x = margin;
    player1.y = screenHeight / 2 - player1.height / 2;
    player1.speed = 12;

    // Player2 parameters
    player2.width = 20;   
    player2.height = 120;
    player2.color = GREEN;
    player2.x = screenWidth - margin - player2.width;
    player2.y = screenHeight / 2 - player2.height / 2;
    player2.speed = 12;

    // while the escape button or the X icon have not been clicked
    while (WindowShouldClose() == false)
    {
        // UPDATE OBJECTS HERE
        ball.move();
        player1.move();

        // Draw
        // ----------------------------------------------------------------------------
        BeginDrawing();
        
        
        //* important to remove old traces of the game
        //? OR IF YOU WANT TO MAKE A VISUALLY APPEALING ANIMATION
        ClearBackground(BLACK);

        // separating line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        
        ball.drawBall();

        player1.draw();
        player2.draw();

        EndDrawing();
    }

    // close the window and finish the game
    CloseWindow();
    return 0;
}