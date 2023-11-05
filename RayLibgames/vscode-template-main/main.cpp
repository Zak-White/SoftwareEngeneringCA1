#include "raylib.h"
#include "rcamera.h"
#include "Player.hpp"


int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Games Dev 2");
    Player player; // create the player
    player.chefPosition = {(float)screenWidth/2,(float)screenHeight/2};
    //Vector2 chefPosition{ (float)screenWidth/2,(float)screenHeight/2};
    //Loading in the textures from the sprite sheets and the backgrounds
    Texture2D background = LoadTexture("./Textures/Backgrounds/Sky.png");
    Texture2D midground = LoadTexture("./Textures/Backgrounds/SkyScrap.png");
    Texture2D foreground = LoadTexture("./Textures/Backgrounds/Fast Food.png");
    player.ChefFront = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");
    //Texture2D ChefFront = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");
    //Vector2 ballPos{(float)chefPosition.x,(float)chefPosition.y};
    player.speed = 2;
    //int speed=2; //This will allow me to create a speed power up or control the players speed. Default is 2
    int burgerspeed =2; // copntrols projectile speeds
    bool fireball = false;
    player.isMovingLeft = false;
    player.isMovingRight = false;
    //bool isMovingLeft = false; //Setting up some example variables
    //bool isMovingRight = false; //Setting up some example variables

    //Setting up a 3d camera example
    /*
        Camera3D playercamera = {0};
    playercamera.position = (Vector3){ 0.0f, 2.0f, 4.0f};   // Camera position
    playercamera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    playercamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    playercamera.fovy = 60.0f;  
    playercamera.projection = CAMERA_PERSPECTIVE;  

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    */

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        //Demo Update for keyboard input

        //if(IsKeyDown(KEY_SPACE)) fireball = true;
        player.move();

        // Setup Canvas
        BeginDrawing();

           // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);


        //3dmode
        /*
                BeginMode3D(playercamera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);
        */


     

        // Here goes all the Game Logic
        
        
        //shapes demo and text
        //DrawRectangle(screenWidth/2 -128, screenHeight/2 -128,256,256,BLACK);
        //DrawRectangle(screenWidth/2 -112, screenHeight/2 -112,224,224,RAYWHITE);
        //DrawText("This is demo",screenWidth/2 -150, screenHeight/2 +48, 50,RED);
        //Drawing a
        DrawTexture(background,0,0,RAYWHITE);
        DrawTexture(midground,0,0,RAYWHITE);
        DrawTexture(foreground,0,0,RAYWHITE);
        player.direction();
 

      
        //Draw circle for move example
        //DrawCircleV(ballPosition,50,GREEN);
        /*
                if(fireball==true)
        {
            DrawCircleV(ballPos,3,GREEN);
            if(isMovingLeft)
            {
                ballPos.x-=burgerspeed;
            }
            else
            {
                ballPos.x+=burgerspeed;
            }
        }

        if(ballPos.x > chefPosition.x+500 || ballPos.x >chefPosition.x-500 )
        {
            // Look into code for destroying the projectile when it leaves these bounds to avoid clutter
            // DrawText("Test Ball",screenWidth/2 -150, screenHeight/2 +48, 50,RED);
        }
        */

        // teardown Canvas
        EndDrawing();

    }
    CloseWindow();
        player.unload();
        UnloadTexture(foreground);
        UnloadTexture(midground);
        UnloadTexture(background);
    return 0;
}