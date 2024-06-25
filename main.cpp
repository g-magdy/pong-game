/**
 * This game is an intro for me to use raylib
 * comments here are for my understanding .. repetition
 *  */

#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "ComputerPaddle.h"

Ball ball;
Paddle player;
ComputerPaddle cpu;

int playerScore = 0;
int CPUScore = 0;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int main()
{
    // Basic setup
    const int screenWidth = 1280;
    const int screenHeight = 800;
    // draw initial window
    InitWindow(screenWidth, screenHeight, "Welcome to the pong game!");

    // this ensures that the following while loop 60 times per second,
    // and not depending on the person's computer
    SetTargetFPS(60);

    // Initialize parameters of objects here
    
    // Ball prameters
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.radius = 15;
    ball.initialSpeed = 10;
    ball.speed_x = 10;
    ball.speed_y = 10;
    ball.color = Yellow;

    // margin between paddle and edge of screen
    const int margin = 12;

    // player parameters
    player.width = 20;
    player.height = 120;
    player.color = WHITE;
    player.x = margin;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 12;

    // cpu parameters
    cpu.width = 20;   
    cpu.height = 120;
    cpu.color = BLACK;
    cpu.x = screenWidth - margin - cpu.width;
    cpu.y = screenHeight / 2 - cpu.height / 2;
    cpu.speed = 12;

    // while the escape button or the X icon have not been clicked
    while (WindowShouldClose() == false)
    {
        // UPDATE OBJECTS HERE
        ball.move();
        player.move();
        // cpu.oscillateUpandDown();
        cpu.trackBall(ball.y);

        // update scores and reset ball
        if (ball.x > screenWidth - ball.radius)
        {
            playerScore++;
            // recentre and reflect towards the left (the winner)
            ball.reCentre(0);
        }

        if (ball.x < ball.radius)
        {
            CPUScore++;
            // recentre and reflect towards the right (the winner)
            ball.reCentre(1);
        }

        // Draw
        // ----------------------------------------------------------------------------
        BeginDrawing();
        
        
        //* important to remove old traces of the game
        //? OR IF YOU WANT TO MAKE A VISUALLY APPEALING ANIMATION
        ClearBackground(Dark_Green);
        
        // half the game window
        DrawRectangle(screenWidth/2, 0, screenWidth/2, screenHeight, Green);

        // center circle
        DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
        
        // separating line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        
        ball.drawBall();
        ball.checkCollisionWithPaddle(player.x, player.y, player.width, player.height);
        ball.checkCollisionWithPaddle(cpu.x, cpu.y, cpu.width, cpu.height);

        player.draw();
        cpu.draw();

        // Displaying scores
        const char *s1 = TextFormat("You: %i", playerScore);
        const char *s2 = TextFormat("CPU: %i", CPUScore);
        DrawText(s1, screenWidth/4 - 130, 20, 80, WHITE);
        DrawText(s2, 3* screenWidth/4 - 130, 20, 80, BLACK);

        EndDrawing();
    }

    // close the window and finish the game
    CloseWindow();
    return 0;
}