#include "classes.h"
#include <iostream>

using namespace std;

typedef struct Window{
    float Width;
    float Height;
} Window;

void MovePlayer(Character* player, float dT);

void WindowBorderTrigger(Window mainWindow, Character* player);