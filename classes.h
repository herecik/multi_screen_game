#include "raylib.h"


class Character{
    public:
    Vector2 Pos;
    Rectangle Rec;
    Vector2 Velocity;

    Character(Vector2 pos, Rectangle rec, Vector2 velocity);
    void Move(Vector2 velocities, float dT);
    
};

class Projectile : public Character{
    public:
    bool Exists = false;

    using Character::Character;
    
};

