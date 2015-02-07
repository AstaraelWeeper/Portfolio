
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "SpaceInvaders.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gDoubleBuffer = NULL; //

SDL_Surface* gCurrentSurface = NULL; 

Player* player = NULL;

bool InitialiseSdl()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool InitialiseAssets()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void GameOver()
{
	gCurrentSurface = ? ? //apply explosion asset at ship position
		close();
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gDoubleBuffer);
	gDoubleBuffer = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	int lives = 3;
	//Start up SDL and create window
	if (!InitialiseSdl())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!InitialiseAssets())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Create the player
			player = new Player();

			//Apply the image
			SDL_BlitSurface(gDoubleBuffer, NULL, gScreenSurface, NULL);

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set default current surface
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					//User presses a key
					else if (e.type == SDL_KEYDOWN)
					{
						//Select surfaces based on key press
						switch (e.key.keysym.sym)
						{
						case SDLK_LEFT:
						case SDLK_RIGHT:
							player->Move(e.type);
							break;

						default:
							
							break;
						}
					}
				}

				//Apply the current image
				SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}

//Classes


Player::Player()
{
	shipPosition = new Position();
	shipPosition->x = 304;
	shipPosition->y = 400;
}

void Player::Move(Uint32 direction)
{
	if (direction == SDLK_LEFT)
	{
		if (shipPosition->x>20)
		{
			shipPosition->x -= 20;
		}
	}
	else
	{
		if (shipPosition->x < 620)
		{
			shipPosition->x += 20;
		}
	}
}

void Player::Fire()
{
	Projectile* bullet = new Projectile(shipPosition);
}

Invader::Invader(Position* start)
{
	shipPosition = start;
	phase = 11;
}

void Invader::Move()
{
	switch (phase)
	{
	case 11:
		shipPosition->x += 20; //right
		phase = 12;
		break;

	case 12:
		shipPosition->x += 20; //right
		phase = 13;
		break;

	case 13:
		shipPosition->x += 20; //right
		phase = 14;
		break;

	case 14:
		shipPosition->y += 20; //down
		phase = 21;
		break;

	case 21:
		shipPosition->x -= 20; //left
		phase = 22;
		break;

	case 22:
		shipPosition->x -= 20; //left
		phase = 23;
		break;

	case 23:
		shipPosition->x -= 20; //left
		phase = 24;
		break;
	
	case 24:
		shipPosition->y += 20; //down
		phase = 11;
		break;
	}
}


Projectile::Projectile(Position* startposition)
{
	projPosition = startposition;
}

void Projectile::Move()
{
	projPosition->y -= 40;
}