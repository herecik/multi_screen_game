#include "raylib.h"
#include <iostream>


//forward declaration for shoot function to work
class Projectile;

class Character{
    public:
    Vector2 Pos;
    Rectangle Rec;
    Vector2 Velocity;

    Character(Vector2 pos, Rectangle rec, Vector2 velocity);

    //Gets coordonates of the centre of player
    Vector2 GetCentre(Rectangle rec, Vector2 pos);
    void Move(Vector2 velocities, float dT);
    void Shoot(Projectile *proj, float dT);
    
};

class Projectile : public Character{
    public:
    bool Exists = false;

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
