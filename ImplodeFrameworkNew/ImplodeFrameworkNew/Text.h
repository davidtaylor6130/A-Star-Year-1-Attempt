#pragma once
#include <SDL_ttf.h>
#include <string>

using namespace std;

class Text
{
public:
	Text(const char * ttfLocation, int Size, const char * inputText, SDL_Color inputColor, SDL_Renderer * inputRenderer, bool UpDatePerFrame, int textW, int textH, int inputX, int inputY);
	~Text();

	void UpdateText(const char * inputText);
	void UpdatePosition(int inputX, int inputY);
	void UpdateFont(const char * inputText);
	void UpdateSize(int InputSize);
	void Update();
	void Render();

	SDL_Renderer * renderer;
	SDL_Rect dstrect;

	SDL_Surface * surface;
	SDL_Texture * mTexture;

	TTF_Font * font;
	SDL_Color color;
	int x, y, texW, texH;
	int Size;

	const char * text;

	bool updateText;

};

