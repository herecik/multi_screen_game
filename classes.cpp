#include "classes.h"

Character::Character(Vector2 pos, Rectangle rec, Vector2 velocity ) : Pos(pos), Rec(rec), Velocity(velocity) {};
Level::Level(int id, Texture2D background) : LevelId(id), LevelBackground(background) {};


Window::Window(){
    Width = 1200.f;
    Height = 800.f;
    ActiveLevel = 1;
    InitWindow(Width, Height, "Main Window");
}

void Character::Move(Vector2 velocities, float dT){
    Pos.x += velocities.x * dT;
    Pos.y += velocities.y * dT;
}

void Character::Shoot(Projectile *proj, float dT){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !proj->Exists){
        proj->Exists = true;
        Vector2 positionOfPlayerCentre = GetCentre(Rec, Pos);
        //set up spawn coordonates of projectile
        proj->Pos.x = positionOfPlayerCentre.x;
        proj->Pos.y = positionOfPlayerCentre.y;
    }
    if(proj->Exists){
       
        DrawRectangle(proj->Pos.x,proj->Pos.y,proj->Rec.width, proj->Rec.height, BLUE);
        proj->Move({100,50},dT);
    }
}

Vector2 Character::GetCentre(Rectangle rec, Vector2 pos){
    Vector2 result;
    result.x = pos.x + (rec.width / 2);
    result.y = pos.y + (rec.height / 2);

    return result;

}
