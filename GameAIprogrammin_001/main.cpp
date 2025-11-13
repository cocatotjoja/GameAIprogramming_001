#include "raylib.h"
#include "player.h"
#include "agent.h"
#include "wall.h"

int main()
{
    //Project colors
    Color green = { 176, 190, 162, 255 };
    Color brown = { 186, 155, 141, 255 };
    Color burgundy = { 111, 50, 60, 255 };

    // Create Wall array
    Wall walls[4];
    walls[0] = Wall(Vector2{ 10, 10 }, Vector2{ 780, 0 });
    walls[1] = Wall(Vector2{ 10, 10 }, Vector2{ 0, 780 });
    walls[2] = Wall(Vector2{ 790, 10 }, Vector2{ 0, 780 });
    walls[3] = Wall(Vector2{ 10, 790 }, Vector2{ 780, 0 });
    
    // Create Player (controlled with arrow keys)
    Player player;

    // Create Agent(s)
    Agent agents[5];
    Agent agent(Vector2 {200, 200}, Vector2 {0 , 0});

    // Create Window and set FPS
    InitWindow(800, 800, "Ai Movement");
    SetTargetFPS(60);



    //Game Loop
    while (WindowShouldClose() == false)
    {
        // Updating
        player.Update();
        agent.CheckState();
        agent.Update(player.GetPosition(),player.GetVelocity(), agents, walls);

        // Drawing
        BeginDrawing();
        ClearBackground(brown);
        player.Draw(burgundy);
        agent.Draw();
        for (int i = 0; i < 4; i++)
        {
            walls[i].Draw(burgundy);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}