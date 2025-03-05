#include "main.h"





int main(){
    //creatre gamne window
    Window MainWindow;
    MainWindow.Height = 800.f;
    MainWindow.Width = 1200.f;
    InitWindow(MainWindow.Width, MainWindow.Height, "Game");
    //init player character
    Vector2 CharVelocity{0,0}; 
    Character* Player = new Character({MainWindow.Width/2, MainWindow.Height/2},{0,0,50,50},CharVelocity);

    Projectile* Proj = new Projectile(Player->GetCentre(Player->Rec, Player->Pos),{0,0,10,10},{0,0});

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        float dT = GetFrameTime();
        BeginDrawing();
        ClearBackground(GRAY);
    
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
        
        
        //mouse position 
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

void MovePlayer(Character* player, float dT){
    float velocity = 200;
    if(IsKeyDown(KEY_A)){
        player->Move({-200,0}, dT);
        cout << "ok" << endl;
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
    if(mainWindow.Width < player->Pos.x){
        cout << "BINGO" << endl;
    }
    
}