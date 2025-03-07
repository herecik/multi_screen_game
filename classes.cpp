#include "classes.h"

Character::Character(Vector2 pos, Rectangle rec, float speed ) : Pos(pos), Rec(rec), Speed(speed) {};
Level::Level(int id, Texture2D background) : LevelId(id), LevelBackground(background) {};


Window::Window(){
    Width = 1200.f;
    Height = 800.f;
    ActiveLevel = 1;
    InitWindow(Width, Height, "Main Window");
}

void Character::Move(float dT){

    if(IsKeyDown(KEY_A)){
        Velocity.x = -Speed;
    }
    if(IsKeyDown(KEY_D)){
        Velocity.x = Speed;
    }
    if(IsKeyDown(KEY_W)){
        Velocity.y = -Speed;
    }
    if(IsKeyDown(KEY_S)){
        Velocity.y = Speed;
    }
    ChangePosition(dT);
    Velocity = {0,0};
}

void Character::ChangePosition(float dT){
    Pos.x += Velocity.x * dT;
    Pos.y += Velocity.y * dT;
}

void Character::Shoot(Projectile *proj, float dT){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !proj->Exists){
        proj->Exists = true;
        Vector2 positionOfPlayerCentre = GetCentre(Rec, Pos);

        // Nastavení počáteční pozice střely
        proj->Pos = positionOfPlayerCentre;

        // Výpočet směru střely k myši
        Vector2 mousePos = GetMousePosition();
        Vector2 direction = {mousePos.x - proj->Pos.x, mousePos.y - proj->Pos.y};
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);

        // Normalizace směru
        if (length != 0) {
            direction.x /= length;
            direction.y /= length;
        }

        // Nastavení konstantního směru střely
        proj->ProjectileVelocity = {direction.x * proj->Speed, direction.y * proj->Speed};
    }

    if(proj->Exists){
        proj->Pos.x += proj->ProjectileVelocity.x * dT;
        proj->Pos.y += proj->ProjectileVelocity.y * dT;

        // Vykreslení projektilu
        DrawRectangle(proj->Pos.x, proj->Pos.y, proj->Rec.width, proj->Rec.height, BLUE);
    }
}

Vector2 Character::GetCentre(Rectangle rec, Vector2 pos){
    Vector2 result;
    result.x = pos.x + (rec.width / 2);
    result.y = pos.y + (rec.height / 2);

    return result;

}
