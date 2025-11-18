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
    Color burgundy = { 111, 50, 60, 255 };

    //Window size
    float width = 1400;
    float height = 1400;
    float margin = 0;

    // Create Window and set FPS
    InitWindow(width, height, "Ai Movement");
    SetTargetFPS(60);

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
    /*
    agents[0] = Agent(Vector2 {400, 400}, Vector2 {0 , 0}, 0);
    agents[1] = Agent(Vector2 {800, 400}, Vector2 {0 , 0}, 1);
    agents[2] = Agent(Vector2 {400, 600}, Vector2 {0 , 0}, 2);
    agents[3] = Agent(Vector2 {500, 300}, Vector2 {0 , 0}, 3);
    agents[4] = Agent(Vector2 {300, 300}, Vector2 {0 , 0}, 4);
    */




    //Game Loop
    while (WindowShouldClose() == false)
    {
        // Updating
        player.Update();

        // Update agents
        for (int i = 0; i < 5; i++)
        {
            agents[i].CheckState();
            agents[i].Update(player.GetPosition(),player.GetVelocity(), agents, walls, obstacles, width, height);
        }

        // Drawing
        BeginDrawing();
        ClearBackground(brown);

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