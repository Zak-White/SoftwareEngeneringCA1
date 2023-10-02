#include "raylib.h"
#include "rcamera.h"

int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1280;
    const int screenHeight = 720;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Games Dev 2");

    Vector2 chefPosition{ (float)screenWidth/2,(float)screenHeight/2};
    //Loading in the textures from the sprite sheets and the backgrounds
    Texture2D background = LoadTexture("./Textures/Backgrounds/Sky.png");
    Texture2D midground = LoadTexture("./Textures/Backgrounds/SkyScrap.png");
    Texture2D foreground = LoadTexture("./Textures/Backgrounds/Fast Food.png");
    Texture2D ChefFront = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");

    //Setting up some example variables
    bool isMovingLeft = false;
    bool isMovingRight = false;

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
        if(IsKeyDown(KEY_RIGHT)) chefPosition.x +=2, isMovingRight = true;
        if(IsKeyDown(KEY_LEFT)) chefPosition.x -=2, isMovingLeft = true;
        if(!IsKeyDown(KEY_RIGHT)) isMovingRight = false;
        if(!IsKeyDown(KEY_LEFT))  isMovingLeft = false;
        if(IsKeyDown(KEY_UP)) chefPosition.y -=2;
        if(IsKeyDown(KEY_DOWN)) chefPosition.y +=2;

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
    
 

        
        if(isMovingLeft)
        {
        DrawTextureRec(ChefFront,
        Rectangle{134,35,18,32},
        Vector2{chefPosition},
        RAYWHITE);
        }

        else if(isMovingRight)
        {
        DrawTextureRec(ChefFront,
        Rectangle{134,66,18,32},
        Vector2{chefPosition},
        RAYWHITE);
        }
        else
        {
        DrawTextureRec(ChefFront,
        Rectangle{128,0,29,32},
        Vector2{chefPosition},
        RAYWHITE);
        }
        //Draw circle for move example
        //DrawCircleV(ballPosition,50,GREEN);
        

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}