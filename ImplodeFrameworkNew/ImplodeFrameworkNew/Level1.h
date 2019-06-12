#pragma once
#include "GameScreen.h"

class Level1 : public GameScreen
{
public:
	int xPos;
	int yPos;
	Sprite* sprite;
	Animation* anim;
	Text * text;
	Level1(SDL_Renderer* renderer);
	~Level1();
	void Render();
	void Update(float deltaTime, SDL_Event e);
private:
};
