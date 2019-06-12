#include "Text.h"
#include <string>

Text::Text(const char * ttfLocation, int InputSize, const char * inputText, SDL_Color inputColor, SDL_Renderer * inputRenderer, bool UpdatePerFrame, int textW, int textH, int inputX, int inputY)
{
	x = inputX;
	y = inputY;
	Size = InputSize;
	font = TTF_OpenFont(ttfLocation, Size);
	text = inputText;
	color = inputColor;
	renderer = inputRenderer;
	updateText = UpdatePerFrame;
	texW = textW;
	texH = textH;

	if (UpdatePerFrame == false)
	{
		surface = TTF_RenderText_Solid(font, text, color);
		mTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_QueryTexture(mTexture, NULL, NULL, &textW, &textH);
		dstrect = { x, y, texW, texH };
	}
}

Text::~Text()
{
	TTF_CloseFont(font);
	SDL_DestroyTexture(mTexture);
	SDL_FreeSurface(surface);
}

void Text::UpdateText(const char * inputText)
{
	text = inputText;
}

void Text::UpdatePosition(int inputX, int inputY)
{
	x = inputX;
	y = inputY;
}

void Text::UpdateFont(const char * inputText)
{
	font = TTF_OpenFont(inputText, Size);
}

void Text::UpdateSize(int InputSize)
{
	Size = InputSize;
}

void Text::Update()
{

}

void Text::Render()
{
	if (updateText == true)
	{
		SDL_QueryTexture(mTexture, NULL, NULL, &texW, &texH);
		dstrect = { x, y, texW, texH };
		surface = TTF_RenderText_Solid(font, text, color);
		mTexture = SDL_CreateTextureFromSurface(renderer, surface);
	}

	SDL_RenderCopy(renderer, mTexture, NULL, &dstrect);
}
