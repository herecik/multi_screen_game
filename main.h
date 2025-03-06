#include "classes.h"
#include <iostream>

using namespace std;

void MovePlayer(Character* player, float dT);

void initMainWindow(Window window);

//Function that triggers if player passes the borders of game window
//triggers only if the player is no longer visible
void WindowBorderTrigger(Window* mainWindow, Character* player, Level* level);
//Prepares all levels
void InitLevels();
//Draws background for specified level
void DrawBackgroundLevel(Level* level);