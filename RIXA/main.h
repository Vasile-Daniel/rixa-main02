#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER

#include <iostream>
#include "Play.h"
#include "Camera.h"


int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;


//what is the state of the game
struct GameState
{
	float timer = 0;
	int spriteId = 0;

	// Player attributes
	int speed = 10;
	float angle; // Angle is the speed of bidirectional movement
};

//what are the types of game objects
enum GameObjectType
{
	TYPE_NULL = -1,
	angel,
	projectile,
	enemy,
	background,
	TYPE_ENEMY,
	TYPE_TOOL,
};

enum AngelState
{
	STATE_APPEAR = 0,
	STATE_HALT,
	STATE_PLAY,
	STATE_DEAD,
};

inline AngelState angelState = STATE_APPEAR;