#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "structs.h"

class Sprite {
public:
	Sprite(const char* filePath, SDL_Renderer* renderer);
	~Sprite();

	void Render(Vector2D position, SDL_RendererFlip flip, double angle = 0.0);
	void Render(Rect2D sourceRect, Rect2D destRect, SDL_RendererFlip flip, double angle = 0.0);

	int GetWidth() { return width; }
	int GetHeight() { return height; }
private:
	SDL_Renderer* mRenderer;

	SDL_Texture* texture = nullptr;
	int width = 0, height = 0;
};