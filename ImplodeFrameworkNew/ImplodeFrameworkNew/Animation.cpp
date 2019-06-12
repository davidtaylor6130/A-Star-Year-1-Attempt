#include "Animation.h"

Animation::Animation(const char* filePath, int frameWidth, int frameHeight, int _frameCount, float _sample, SDL_Renderer* renderer) {
	sprite = new Sprite(filePath, renderer);

	w = frameWidth;
	h = frameHeight;
	frameCount = _frameCount;
	sample = _sample;

	//Create frame rects
	if (sprite->GetWidth() > frameWidth || sprite->GetHeight() > frameHeight) {
		int frameCountX = floor(sprite->GetWidth() / frameWidth);
		int frameCountY = floor(sprite->GetHeight() / frameHeight);

		for (int y = 0; y < frameCountY; y++) {
			for (int x = 0; x < frameCountX; x++) {
				frames.push_back(Rect2D(w * x, h * y, w, h));
			}
		}

	} else {
		std::cout << "Error Code 0.0.10, Specified frame size larger than image size" << std::endl;
		w = sprite->GetWidth();
		h = sprite->GetHeight();
		frames.push_back(Rect2D(0, 0, w, h));
	}
	
	if (frames.size() > frameCount) {
		frames.resize(frameCount);
	} else {
		std::cout << "Error Code 0.0.11, Specified frame count larger than possible frame count" << std::endl;
	}
}

Animation::~Animation() {
	delete sprite;
	sprite = nullptr;
}

void Animation::Update(float deltaTime) {
	curFrameTime += deltaTime;

	if (curFrameTime >= sample) {
		curFrameTime = 0;
		curFrame++;
		curFrame %= frames.size();
	}
}

void Animation::Render(Vector2D position, SDL_RendererFlip flip, double angle) {
	Rect2D dest(position.x, position.y, w, h);
	sprite->Render(frames[curFrame], dest, flip, angle);
}