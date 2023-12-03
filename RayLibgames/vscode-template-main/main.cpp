#include "raylib.h"
#include "rcamera.h"
#include "raymath.h"
#include <stdlib.h>
#include <iostream>
#include "Player.hpp"
#include "MainMenu.hpp"
#include "Enemy.hpp"
#include "projectile.hpp"



using namespace std;
int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "The Deadliest Burger");

    //This is where all my major crashes came from. I had to just go over constructors again because I needed a refresher
    // Used https://stackoverflow.com/questions/18939673/how-to-call-constructors-in-main and https://github.com/ethan-reilly/ethan-zak-MDP-CA2/blob/main/GD4SFMLCode23/Aircraft.cpp
    //A a4(7);       // <-- constructs object using the constructor taking int This particular line helped me figure out my issue
    Music backgroundmusic = LoadMusicStream("./Textures/Music/Background.mp3");
    backgroundmusic.looping = true;
    float pitch = 1.0f;
    PlayMusicStream(backgroundmusic); //https://www.raylib.com/examples.html Audio Example
    Player player(false,Rectangle{},0,4); // create the player
    MainMenu menu;
    Enemy enemy = {0,1,Rectangle{0,0},0,0.0,1.0f/20.0f,0.0f};
    //Enemy enemy[10];
    projectile projectile(1,Vector2{0.0,0.0},Rectangle{0,0},0,0.0f,1.0f/20.0f);
    //setting up some basic menu variables
    menu.exitWindowRequested = false;
    menu.exitWndow = false;
    //for(int i = 0; i<= 10; i++)
    //{
    //    enemy[i].setLives();
    //}
    enemy.setLives();
    projectile.setLives();

    SetExitKey(KEY_NULL);
    //player.chefPosition = {(float)screenWidth/2,(float)screenHeight/2};
    //Loading in the textures from the sprite sheets and the backgrounds
    menu.winScreen = LoadTexture("./Textures/Backgrounds/Win.png");
    menu.lossScreen = LoadTexture("./Textures/Backgrounds/Loss.png");
    Texture2D background = LoadTexture("./Textures/Backgrounds/Sky.png");
    Texture2D midground = LoadTexture("./Textures/Backgrounds/SkyScrap.png");
    Texture2D foreground = LoadTexture("./Textures/Backgrounds/Fast Food.png");
    //player.ChefFront = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");
    menu.inMainMenu=true;
    player.speed = 2;
    projectile.speed = 4;
    //enemy.updatetime=1/10; was testing a theory a game theory.
    player.sourcerec = (Rectangle){0.0f,0.0f,(float)(player.Sprite.width),(float)(player.Sprite.height)};
    //for(int i = 0; i<= 10; i++)
     //   {
     //       enemy[i].rec = (Rectangle){0.0f,0.0f,(float)(enemy[i].Sprite.width),(float)(enemy[i].Sprite.height)};
     //   }    
     enemy.rec = (Rectangle){0.0f,0.0f,(float)(enemy.Sprite.width),(float)(enemy.Sprite.height)};
    projectile.rec = (Rectangle){0.0f,0.0f,(float)(projectile.Sprite.width),(float(projectile.Sprite.width))};
    //for(int i = 0; i<= 10; i++)
    //{
    //    enemy[i].Alive=true;
   // }
    enemy.Alive=true;
    projectile.Alive=true;
    //int burgerspeed =2; // controls projectile speeds
    //bool fireball = false; // if the player is firing
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
        UpdateMusicStream(backgroundmusic);
        SetMusicPitch(backgroundmusic,pitch);
        //if(IsKeyDown(KEY_SPACE)) fireball = true;
        player.move();


        // Setup Canvas
        BeginDrawing();

        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

        projectile.intitalPostion.x = player.position.x;
        projectile.position.y = player.position.y;
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
        if(menu.inMainMenu==true)
        {
            DrawRectangle(0, 100, 1280, 200, BLACK);
            DrawText("MAIN MENU",40, 180, 30, WHITE);
            if(IsKeyPressed(KEY_ENTER))
            {
                menu.inMainMenu=false;
                menu.inDifficultyMenu=true;
            }
        }
        if(menu.inDifficultyMenu==true)
        {
            DrawRectangle(0, 100, 1280, 200, BLACK);
            DrawText("Press 1 = Easy, Press 2 = Normal, Press 3 = Hard",40, 180, 30, WHITE);
            if(IsKeyPressed(KEY_KP_1))
            {
                menu.inMainMenu=false;
                menu.inDifficultyMenu=false;
                //for(int i =0; i <=10; i++)
                //{
                //    enemy[i].difficulty=1;
                //}
                enemy.difficulty=1;
            }
            else if(IsKeyPressed(KEY_KP_2))
            {
                menu.inMainMenu=false;
                menu.inDifficultyMenu=false;
                //for(int i =0; i <=10; i++)
                //{
                //    enemy[i].difficulty=2;
                //}
                enemy.difficulty=2;
            }
            else if(IsKeyPressed(KEY_KP_3))
            {
                menu.inMainMenu=false;
                menu.inDifficultyMenu=false;
                //for(int i =0; i <=10; i++)
                //{
                //    enemy[i].difficulty=3;
                //}
                enemy.difficulty=3;
            }
        }
        
        //shapes demo and text
        //DrawRectangle(screenWidth/2 -128, screenHeight/2 -128,256,256,BLACK);
        //DrawRectangle(screenWidth/2 -112, screenHeight/2 -112,224,224,RAYWHITE);
        //DrawText("This is demo",screenWidth/2 -150, screenHeight/2 +48, 50,RED);
        //Drawing a
        if(menu.inDifficultyMenu==false && menu.inMainMenu==false)
        {
        
        DrawTexture(background,0,0,RAYWHITE);
        DrawTexture(midground,0,0,RAYWHITE);
        DrawTexture(foreground,0,0,RAYWHITE);
        menu.requestClose();
        menu.DrawCloseMenu();
        
        player.direction();
        player.checkBorder();
        player.playerKillsIncrease();
       // for(int i =0; i <=10; i++)
        //{
         //   enemy[i].animation();
          ///  enemy[i].difficultychange();
            //enemy[i].move();
            //enemy[i].drawEnemy();
        //}
            enemy.animation();
            enemy.difficultychange();
            enemy.move();
            enemy.drawEnemy();
            

        projectile.fire();
        projectile.move();
        projectile.despawn();
          if(player.ismovingleft==true)
        {
            projectile.ismovingleft=true;
            projectile.ismovingright=false;
        }
        else if(player.ismovingright==true)
        {
            projectile.ismovingright=true;
            projectile.ismovingleft=false;
        }
        
        
             if(enemy.position.x == projectile.position.x)
            {

            enemy.decreaseLives();
            projectile.projectileDecreaseLives();
            player.increaseKills();
            }

            if(enemy.position.x == player.position.x && enemy.Alive==true)
            {

            enemy.decreaseLives();
            player.decreaseLives();
            
            }
        projectile.kill();
        enemy.kill();
        enemy.respawn();
        
        player.endGame();
        //enemy.deltaTime=GetFrameTime();
        if(player.hasWon==true)
        {
            menu.playerVictory();
        }
        else if(player.hasLost == true)
        {
            menu.playerLoss();
        }
        cout<<projectile.Alive<<endl;
        //cout<<enemy.position.x<<endl;
        //cout<<player.position.x<<endl;
        //cout<<projectile.firing<<endl;
        //cout << enemy.position.x << endl;
        //cout<<enemy.deltaTime<<endl;
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
        }
       
        EndDrawing();

    }
    CloseAudioDevice();
    CloseWindow();
        UnloadMusicStream(backgroundmusic);

        player.unload();
        UnloadTexture(foreground);
        UnloadTexture(midground);
        UnloadTexture(background);
    return 0;
}