#include "classes.h"
#include <iostream>

using namespace std;

typedef struct Window{
    float Width;
    float Height;
} Window;

void MovePlayer(Character* player, float dT);

//Function that triggers if player passes the borders of game window
//triggers only if the player is no longer visible
void WindowBorderTrigger(Window mainWindow, Character* player);