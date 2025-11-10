#include "raylib.h"
#include "player.h"

int main()
{
    int ballX = 400;
    int ballY = 400;
    Color green = { 176, 190, 162, 255 };
    Color brown = { 186, 155, 141, 255 };
    Color burgundy = { 111, 50, 60, 255 };

    InitWindow(800, 800, "Ai Movement");
    SetTargetFPS(60);

    Player player;


    //Game Loop
    while (WindowShouldClose() == false)
    {
        // 1. Event Handling
        player.Update();

        // 2. Updating Positions

        // 3. Drawing
        BeginDrawing();
        ClearBackground(brown);
        player.Draw(burgundy);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}