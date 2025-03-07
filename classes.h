#include "raylib.h"
#include <iostream>
#include <cmath>

//forward declaration for shoot function to work
class Projectile;

class Character{
    public:
    Vector2 Pos;
    Rectangle Rec;
    Vector2 Velocity = {0,0};
    float Speed;

    Character(Vector2 pos, Rectangle rec, float speed);

    //Gets coordonates of the centre of player
    Vector2 GetCentre(Rectangle rec, Vector2 pos);
    void Move(float dT);
    void ChangePosition(float dT);
    void Shoot(Projectile *proj, float dT);
    
};

class Projectile : public Character{
    public:
    bool Exists = false;
    float ProjectileTime = 2.f;
    float AliveTimer = 0.f;
    Vector2 ProjectileVelocity = {0,0};


    using Character::Character;
    
};

class Level{
    public:
    int LevelId;
    Texture2D LevelBackground;
    Level(int id, Texture2D background);
};
//class for main game window
class Window{
    public:
    float Height;
    float Width;
    int ActiveLevel;
    Window();
};
