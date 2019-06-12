#pragma once
#include "Sprite.h"
#include "structs.h"
#include <vector>
#include <iostream>

class Animation {
public:
	Animation(const char* filePath, int frameWidth, int frameHeight, int frameCount, float _sample, SDL_Renderer* renderer);
	~Animation();

	void Update(float deltaTime);
	void Render(Vector2D position, SDL_RendererFlip flip, double angle = 0.0);

	int GetWidth() { return w; }
	int GetHeight() { return h; }

private:
	Sprite* sprite;
	int w, h;
	int frameCount;
	float sample;

	std::vector<Rect2D> frames;
	int curFrame = 0;
	float curFrameTime = 0;
};