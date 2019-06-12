#include "GameScreenManager.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, GameScreen * screen)
{
	mRenderer = renderer; //firstly we need to set the renderer
	mCurrentScreen = NULL; //next we set the current screen to null since one hasn't be set just yet
	ChangeScreen(screen); //finally we call changescreen to the screen value that has been passed in
}

GameScreenManager::~GameScreenManager()
{
	mRenderer = NULL;
	delete mCurrentScreen;
	mCurrentScreen = NULL;
}

void GameScreenManager::Render()
{
	mCurrentScreen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	mCurrentScreen->Update(deltaTime,e);
}

void GameScreenManager::ChangeScreen(GameScreen * newScreen)
{
	if (mCurrentScreen != NULL) //Firstly we check if a current screen exists
	{
		delete mCurrentScreen; 
	}
	//Now set the current screen
	mCurrentScreen = newScreen;
}