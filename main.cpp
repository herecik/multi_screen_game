#include "main.h"

int main(){
    //creatre gamne window
    Window MainWindow;
    MainWindow.Height = 800.f;
    MainWindow.Width = 1200.f;
    InitWindow(MainWindow.Width, MainWindow.Height, "Game");
    //InitLevels
    Level *Level1 = new Level(1, LoadTexture("textures/bcg1.png"));
    Level *Level2 = new Level(2, LoadTexture("textures/bcg1.png"));
    //init player character
    Vector2 CharVelocity{0,0}; 
    Character* Player = new Character({MainWindow.Width/2, MainWindow.Height/2},{0,0,50,50},CharVelocity);

    Projectile* Proj = new Projectile(Player->GetCentre(Player->Rec, Player->Pos),{0,0,10,10},{0,0});

    SetTargetFPS(60);
    while(!WindowShouldClose()){


        float dT = GetFrameTime();
        BeginDrawing();
        ClearBackground(GRAY);
        DrawBackgroundLevel(Level1);
    
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
    CloseWindow();
    
    return 0;
}

void InitLevels(){
    
}

void DrawBackgroundLevel(Level* level){
    DrawTexture(level->LevelBackground, 0, 0, WHITE);
    switch (level->LevelId)
    {
    case  1:
        cout << "LevelId: " << level->LevelId << endl;
        break;
    case 2:
        cout << "LevelId: " << level->LevelId << endl;

    default:
        break;
    }
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

void WindowBorderTrigger(Window mainWindow, Character* player){
    //Right border
    if(mainWindow.Width < player->Pos.x){
        cout << "BINGO" << endl;
    }
    //Left Border
    if(0 > player->Pos.x + player->Rec.width){
        cout << "BINGO" << endl;
    }
    //Upper border
    if(0 > player->Pos.y + player->Rec.height){
        cout << "BINGO" << endl;
    }
    //Bottom border
    if(mainWindow.Height < player->Pos.y){
        cout << "BINGO" << endl;
    }
}