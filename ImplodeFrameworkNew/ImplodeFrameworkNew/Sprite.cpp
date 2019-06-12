#include "Sprite.h"

Sprite::Sprite(const char* filePath, SDL_Renderer* renderer) {
	mRenderer = renderer;

	//Load image
	SDL_Surface* pSurface = IMG_Load(filePath);
	if (pSurface != nullptr) {
		//Colour Key the image - the colour to be transparent.
		SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0xFF, 0xFF));

		//Create texture from pixels on the surface
		texture = SDL_CreateTextureFromSurface(mRenderer, pSurface);

		//Set width and height
		width = pSurface->w;
		height = pSurface->h;

		if (texture == nullptr) {
			std::cout << "ERROR CODE 0.0.7, Unable to create texture from surface. Error: " << SDL_GetError() << std::endl;
		}
		//Remove loaded surface now that we've used it
		SDL_FreeSurface(pSurface);
	} else {
		std::cout << "ERROR CODE 0.0.8, Unable to create surface. Error: " << IMG_GetError() << std::endl;
	}
}

Sprite::~Sprite() {
	delete texture;
	mRenderer = nullptr;
}

void Sprite::Render(Vector2D position, SDL_RendererFlip flip, double angle) {
	//Set where to render the texture and texture size
	SDL_Rect renderLocation = { position.x, position.y, width, height };

	//Render to screen
	SDL_RenderCopyEx(mRenderer, texture, NULL, &renderLocation, angle, NULL, flip);
}

void Sprite::Render(Rect2D sourceRect, Rect2D destRect, SDL_RendererFlip flip, double angle) {
	SDL_Rect src = { sourceRect.x, sourceRect.y, sourceRect.width, sourceRect.height };
	SDL_Rect dest = { destRect.x, destRect.y, destRect.width, destRect.height };

	SDL_RenderCopyEx(mRenderer, texture, &src, &dest, angle, NULL, flip);
}
