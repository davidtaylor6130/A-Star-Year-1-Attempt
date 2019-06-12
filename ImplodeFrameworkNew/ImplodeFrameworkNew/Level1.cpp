#include "Level1.h"

Level1::Level1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	xPos = 0;
	yPos = 0;
	anim = new Animation("test.png", 500, 295, 17, 0.08f, renderer);
	SDL_Color tempColor = { 50,50,50 };
	text = new Text("ttf/8-BIT_WONDER.TTF", 200, "hello", tempColor, renderer, false, 100, 100, 100 ,500);
	sprite = new Sprite("test.png", renderer);
}

Level1::~Level1()
{
}

void Level1::Render()
{
	text->Render();
	anim->Render(Vector2D(xPos, yPos), SDL_FLIP_NONE);
}

void Level1::Update(float deltaTime, SDL_Event e)
{
	text->Update();

	if (isKeyDown(('s'),e))
	{
		yPos += 5;
	}
	anim->Update(deltaTime);
}
