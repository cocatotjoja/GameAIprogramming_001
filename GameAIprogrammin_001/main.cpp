#include "raylib.h"
#include "player.h"
#include "agent.h"

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
    Agent agent1(Vector2 {200, 200}, Vector2 {0 , 0});
    //Agent agent2(Vector2 {600, 600}, Vector2 {0 , 0});


    //Game Loop
    while (WindowShouldClose() == false)
    {
        // Updating
        agent1.CheckState();
        player.Update();
        agent1.Update(player.GetPosition(),player.GetVelocity());
        //agent2.Update(player.GetPosition(),player.GetVelocity());

        // Drawing
        BeginDrawing();
        ClearBackground(brown);
        player.Draw(burgundy);
        agent1.Draw(green);
        //agent2.Draw(green);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}