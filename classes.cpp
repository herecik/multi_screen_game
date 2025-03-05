#include "classes.h"

Character::Character(Vector2 pos, Rectangle rec, Vector2 velocity ) : Pos(pos), Rec(rec), Velocity(velocity) {};

void Character::Move(Vector2 velocities, float dT){
    Pos.x += velocities.x * dT;
    Pos.y += velocities.y * dT;
}

Vector2 Character::GetCentre(Rectangle rec, Vector2 pos){
    Vector2 result;
    result.x = pos.x + (rec.width / 2);
    result.y = pos.y + (rec.height / 2);

    return result;

}
