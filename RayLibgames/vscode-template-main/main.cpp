#include "raylib.h"
#include "rcamera.h"
#include <iostream>
#include "Player.hpp"
#include "MainMenu.hpp"


using namespace std;
int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Games Dev 2");

    //This is where all my major crashes came from. I had to just go over constructors again because I needed a refresher
    // Used https://stackoverflow.com/questions/18939673/how-to-call-constructors-in-main and https://github.com/ethan-reilly/ethan-zak-MDP-CA2/blob/main/GD4SFMLCode23/Aircraft.cpp
    //A a4(7);       // <-- constructs object using the constructor taking int This particular line helped me figure out my issue

    Player player(0,4); // create the player
    MainMenu menu;

    //setting up some basic menu variables
    menu.exitWindowRequested = false;
    menu.exitWndow = false;


    SetExitKey(KEY_NULL);
    //player.chefPosition = {(float)screenWidth/2,(float)screenHeight/2};
    //Loading in the textures from the sprite sheets and the backgrounds
    Texture2D background = LoadTexture("./Textures/Backgrounds/Sky.png");
    Texture2D midground = LoadTexture("./Textures/Backgrounds/SkyScrap.png");
    Texture2D foreground = LoadTexture("./Textures/Backgrounds/Fast Food.png");
    //player.ChefFront = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");

    player.speed = 2;
    int burgerspeed =2; // controls projectile speeds
    bool fireball = false; // if the player is firing
    //player.isMovingLeft = false;
    //player.isMovingRight = false;

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
    while (!menu.exitWndow /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

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
        menu.requestClose();
        menu.DrawCloseMenu();
        player.direction();
        player.checkBorder();
        player.playerKillsIncrease();
        player.endGame();
        //cout<<player.chefPosition.x<<endl; Testing the players position
        //cout<<player.kills<<endl;
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