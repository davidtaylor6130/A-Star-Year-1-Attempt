#include "GameScreen.h"

GameScreen::GameScreen(SDL_Renderer* renderer)
{
	mRenderer = renderer;
}

GameScreen::~GameScreen()
{
	if (mRenderer != NULL) //Does mRenderer still hold a renderer?
	{
		mRenderer = NULL; //Set the renderer to NULL
	}
}

void GameScreen::Render()
{

}

void GameScreen::Update(float deltaTime, SDL_Event e)
{

}
