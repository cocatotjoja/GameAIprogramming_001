#include "raylib.h"
#include "player.h"
#include "agent.h"
#include "wall.h"
#include "obstacle.h"

int main()
{
    //Project colors
    Color green = { 176, 190, 162, 255 };
    Color brown = { 186, 155, 141, 255 };
    Color darkBrown = { 140, 117, 106, 255 };
    Color burgundy = { 111, 50, 60, 255 };

    //Window size
    float width = 1400;
    float height = 1400;
    float margin = 0;

    // Create Window and set FPS
    InitWindow(width, height, "Ai Movement");
    SetTargetFPS(60);

    // Create Path array
    Vector2 path[8];
    path[0] = Vector2{ 1200, 800 };
    path[1] = Vector2{ 900, 1100 };
    path[2] = Vector2{ 500, 1150 };
    path[3] = Vector2{ 300, 1000 };
    path[4] = Vector2{ 300, 700 };
    path[5] = Vector2{ 200, 300 };
    path[6] = Vector2{ 600, 350 };
    path[7] = Vector2{ 1100, 300 };

    // Create Wall array
    Wall walls[3];
    for (int i = 0; i < 3; i++)
    {
        walls[i] = Wall(width, height, margin);
    }
    /*
    walls[0] = Wall(Vector2{ margin, margin }, Vector2{ width - (margin*2), 0 });
    walls[1] = Wall(Vector2{ margin, height - margin }, Vector2{ 0, -(height - (margin * 2)) });
    walls[2] = Wall(Vector2{ width - margin, margin }, Vector2{ 0, height - (margin * 2) });
    walls[3] = Wall(Vector2{ margin, height - margin }, Vector2{ width - (margin * 2), 0 });
    */

    // Create Obstacle array
    Obstacle obstacles[3];
    obstacles[0] = Obstacle(Vector2{ 300, 600 }, 25);
    obstacles[1] = Obstacle(Vector2{ 600, 400 }, 30);
    obstacles[2] = Obstacle(Vector2{ 700, 600 }, 40);
    
    // Create Player (controlled with arrow keys)
    Player player;

    // Create Agent(s)
    Agent agents[5];
    for (int i = 0; i < 5; i++)
    {
        agents[i] = Agent(i, width, height, margin);
    }



    //Game Loop
    while (WindowShouldClose() == false)
    {
        // Updating
        player.Update();

        // Update agents
        for (int i = 0; i < 5; i++)
        {
            agents[i].CheckState();
            agents[i].Update(player.GetPosition(),player.GetVelocity(), agents, walls, obstacles, path, width, height);
        }

        // Drawing
        BeginDrawing();
        ClearBackground(brown);

        // Draw path
        DrawLine(path[0].x, path[0].y, path[1].x, path[1].y, darkBrown);
        DrawLine(path[1].x, path[1].y, path[2].x, path[2].y, darkBrown);
        DrawLine(path[2].x, path[2].y, path[3].x, path[3].y, darkBrown);
        DrawLine(path[3].x, path[3].y, path[4].x, path[4].y, darkBrown);
        DrawLine(path[4].x, path[4].y, path[5].x, path[5].y, darkBrown);
        DrawLine(path[5].x, path[5].y, path[6].x, path[6].y, darkBrown);
        DrawLine(path[6].x, path[6].y, path[7].x, path[7].y, darkBrown);
        DrawLine(path[7].x, path[7].y, path[0].x, path[0].y, darkBrown);

        // Draw walls
        for (int i = 0; i < 3; i++)
        {
            walls[i].Draw(burgundy);
        }

        // Draw obstacles
        for (int i = 0; i < 3; i++)
        {
            obstacles[i].Draw(burgundy);
        }

        player.Draw(burgundy);

        // Draw agents
        for (int i = 0; i < 5; i++)
        {
            agents[i].Draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}