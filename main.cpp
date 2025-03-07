#include "main.h"

int main(){
    //creatre gamne window
    Window* MainWindow = new Window();
    
    //InitLevels
    
    //init player character
    Vector2 CharVelocity{0,0}; 
    Character* Player = new Character({MainWindow->Width/2, MainWindow->Height/2},{0,0,50,50},CharVelocity);
    Level *Level1 = new Level(1, LoadTexture("textures/bcg1.png"));
    Level *Level2 = new Level(2, LoadTexture("textures/bcg2.png"));
    Projectile* Proj = new Projectile(Player->GetCentre(Player->Rec, Player->Pos),{0,0,10,10},{0,0});

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



        //Player movement
        MovePlayer(Player, dT);
        //Player shooting
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !Proj->Exists){
            Proj->Exists = true;
            Vector2 positionOfPlayerCentre = Player->GetCentre(Player->Rec, Player->Pos);
            //set up spawn coordonates of projectile
            Proj->Pos.x = positionOfPlayerCentre.x;
            Proj->Pos.y = positionOfPlayerCentre.y;
            cout << "ok" << endl;
        }
        if(Proj->Exists){
           
            DrawRectangle(Proj->Pos.x,Proj->Pos.y,Proj->Rec.width, Proj->Rec.height, BLUE);
            Proj->Move({100,50},dT);
        }
        
        //mouse position TBD, need for shooting
        int x = GetMouseX();
        int y = GetMouseY();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        cout << "klik na X: " << x << endl << "Klik na Y: " << y << endl;
        }
        
        WindowBorderTrigger(MainWindow, Player);

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

void MovePlayer(Character* player, float dT){
    float velocity = 200;
    if(IsKeyDown(KEY_A)){
        player->Move({-200,0}, dT);
    }
    if(IsKeyDown(KEY_D)){
        player->Move({velocity,0}, dT);
    }
    if(IsKeyDown(KEY_W)){
        player->Move({0,-velocity}, dT);
    }
    if(IsKeyDown(KEY_S)){
        player->Move({0,velocity}, dT);
    }
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