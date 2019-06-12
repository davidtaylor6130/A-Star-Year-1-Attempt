#include "SDLOperations.h"

bool SDLOperations::InitSDL(const char* gameTitle, int screenWidth, int screenHeight, int frequency, int channels, int chunkSize)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //inisialise SDL
	{
		cout << "ERROR CODE 0.0.1, SDL Video failed to initialise! Error: " << SDL_GetError();
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow(gameTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN); //Create a window using gWindow as the value
	}

	if (gWindow == NULL) //is window not defined?
	{
		cout << "ERROR CODE 0.0.2, Couldn't create a window! Error: " << SDL_GetError();
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

	if (gRenderer != NULL) //Is the renderer created?
	{
		//Initialise PNG loading
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags)) //has image initialised incorrectly?
		{
			cout << "ERROR CODE 0.0.3 Couldn't initialise SDL_image!" << SDL_GetError();
			return false;
		}
	}
	else
	{
		cout << "ERROR CODE 0.0.4 Couldn't create a renderer successfully!" << SDL_GetError();
		return false;
	}

	if (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channels, chunkSize) < 0)
	{
		cout << "ERROR CODE 0.0.5 Couldn't initialise the mixer!" << SDL_GetError();
		return false;
	}

	if (TTF_Init() < 0)
	{
		cout << "ERROR CODE 0.0.6 Couldn't initialise TTF Font!" << SDL_GetError();
		return false;
	}

	tempScreen = new GameScreen(gRenderer);

	if (tempScreen == NULL)
	{
		cout << "ERROR CODE 0.0.9 , could not create a temporary gameScreen" << endl;
		return false;
	}

	ScreenManager = new GameScreenManager(gRenderer, tempScreen);

	if (ScreenManager == NULL)
	{
		cout << "ERROR CODE 0.1.0, couldn't create a ScreenManager" << endl;
		return false;
	}
	return true;
}

void SDLOperations::Render()
{
	//Clear the screen
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00); //Set the draw colour using the renderer
	SDL_RenderClear(gRenderer);
	//render GameScreenManager
	ScreenManager->mCurrentScreen->Render();
	//update the screen
	SDL_RenderPresent(gRenderer);
}

void SDLOperations::CloseSdl()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	tempScreen = NULL;
	ScreenManager = NULL;
}

bool SDLOperations::Update()
{
	Uint32 newTime = SDL_GetTicks(); //Take the amount of time elapsed
	//event handler to handle events
	SDL_Event e;
	SDL_PollEvent(&e);
	//switch statnement to check for quit input, if user presses the X button or q the program will quit
	switch (e.type)
	{
	case SDL_QUIT:
		return true;
		break;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_q:
			return true;
			break;
		}
		break;
	}
	//update the game screen pass in the amount of time elapsed and the polled event
	ScreenManager->mCurrentScreen->Update((float)(newTime - gOldTime) / 1000.0f, e);
	gOldTime = newTime; //set the old time to the new time for the next update loop
	return false;
}
