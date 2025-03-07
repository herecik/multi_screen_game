#include "main.h"

int main(){
    //creatre gamne window
    Window* MainWindow = new Window();
    float counter = 0;
    
    //InitLevels
    
    //init player character
    Character* Player = new Character({MainWindow->Width/2, MainWindow->Height/2},{0,0,50,50}, 200.f);
    Level *Level1 = new Level(1, LoadTexture("textures/bcg1.png"));
    Level *Level2 = new Level(2, LoadTexture("textures/bcg2.png"));
    Projectile* Proj = new Projectile({0,0},{0,0,10,10}, 400.f);

    SetTargetFPS(60);
    while(!WindowShouldClose()){


        float dT = GetFrameTime();
        BeginDrawing();
        ClearBackground(GRAY);

        switch (MainWindow->ActiveLevel)
        {
        case  1:
            DrawTexture(Level1->LevelBackground, 0, 0, WHITE);
            break;
        case 2:
            DrawTexture(Level2->LevelBackground, 0, 0, WHITE); 
        default:
            break;
        }
    
        DrawRectangle(Player->Pos.x, Player->Pos.y, Player->Rec.width, Player->Rec.height, RED);

        //Player shooting
        Player->Shoot(Proj, dT);

        //Player movement
        Player->Move(dT);
        
        WindowBorderTrigger(MainWindow, Player);
        counter += dT;
        cout << counter << endl;
        EndDrawing();
    }
    delete Player;
    delete Proj;
    delete MainWindow;
    delete Level1;
    delete Level2;
    CloseWindow();
    
    return 0;
}

void WindowBorderTrigger(Window* mainWindow, Character* player){
    //Right border
    if(mainWindow->Width < player->Pos.x){
        mainWindow->ActiveLevel = 2;
        //move player to the right spot on the new window
        player->Pos = {0,player->Pos.y};
        //here ve load texture level->LevelBackground 
    }
    //Left Border
    if(0 > player->Pos.x + player->Rec.width){
        mainWindow->ActiveLevel = 1;
        player->Pos = {mainWindow->Width - player->Rec.width, player->Pos.y};
    }
    //Upper border
    if(0 > player->Pos.y + player->Rec.height){
        player->Pos = {player->Pos.x, mainWindow->Height - player->Rec.height};
    }
    //Bottom border
    if(mainWindow->Height < player->Pos.y){
        player->Pos = {player->Pos.x, 0};
    }
}