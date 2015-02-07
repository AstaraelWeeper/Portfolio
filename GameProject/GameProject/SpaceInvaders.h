#include <SDL.h>
#include <stdio.h>


class Position
{
public:
	Position();
	~Position();
	int x, y;
};

class Ship
{
public:
	Ship();
	~Ship();
	Position* shipPosition;
	virtual void Move();
	virtual void Fire();
};

class Player :Ship
{
public:
	Player();
	~Player();
	virtual void Move(Uint32 keypress);
	virtual void Fire();
};

class Invader :Ship
{
public:
	Invader(Position* start);
	~Invader();
	virtual void Move();
	virtual void Fire();
private:
	int phase;
};

class Projectile
{
 public:
	Projectile(Position* startposition);
	~Projectile();
	Position* projPosition;
	void Move();
};

void Close(); //user quits
void GameOver(); //user loses, this calls close
//Starts up SDL and creates window
bool InitialiseSdl();

//Loads media
bool InitialiseAssets();
