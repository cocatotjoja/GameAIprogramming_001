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

    //Window size
    int width = 1200;
    int height = 1200;

    // Create Wall array
    Wall walls[4];
    walls[0] = Wall(Vector2{ 200, 200 }, Vector2{ (float)width - 400, 0 });
    walls[1] = Wall(Vector2{ 200, 200 }, Vector2{ 0, (float)height - 400 });
    walls[2] = Wall(Vector2{ (float)width - 200, 200 }, Vector2{ 0, (float)height - 400 });
    walls[3] = Wall(Vector2{ 200, (float)height - 200 }, Vector2{ (float)width - 400, 0 });
    
    // Create Player (controlled with arrow keys)
    Player player;

    // Create Agent(s)
    Agent agents[5];
    Agent agent(Vector2 {400, 400}, Vector2 {0 , 0});

    // Create Window and set FPS
    InitWindow(width, height, "Ai Movement");
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
        for (int i = 0; i < 4; i++)
        {
            walls[i].Draw(burgundy);
        }
        player.Draw(burgundy);
        agent.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}