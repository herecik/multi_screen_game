#include "classes.h"

Character::Character(Vector2 pos, Rectangle rec, Vector2 velocity ) : Pos(pos), Rec(rec), Velocity(velocity) {};

void Character::Move(Vector2 velocities, float dT){
    Pos.x += velocities.x * dT;
    Pos.y += velocities.y * dT;
}
