#include "Level1.h"
#include "Events.h"

Level1::Level1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	location = new Rect2D(0, 0, 150, 150);
	spriteLocation = new Rect2D(200, 200, 150, 150);

	Vector2D temp(0, 0);

	for (int i = 0; i < rows; i++)
	{
		temp.y = i * widthHight;
		for (int j = 0; j < coloms; j++)
		{
			temp.x = j * widthHight;
			tilePlaced[i][j] = new tile(renderer, temp, true);
		}
	}

	tilePlaced[startPosition.y][startPosition.x]->startPoint = true;
	tilePlaced[endPosition.y][endPosition.x]->endPoint = true;

	endPos = endPosition;
	startNode = startPosition;
	currentNode = startNode;
}

Level1::~Level1()
{
}

void Level1::Render()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			tilePlaced[i][j]->render();
		}
	}
}

void Level1::Update(float deltaTime, SDL_Event e)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < coloms; j++) {

			//-- a* calculation --//

			if (isKeyDown(SDLK_m, e) == true && KeyDown == false)
			{
				createRoute();
				KeyDown = true;
			}
			else if (KeyDown == true && isKeyUp(SDLK_m, e) == true)
			{
				KeyDown = false;
			}

			//-- checking for the mouse click -- //

			if (isMouseLeftDown(e) == true || isMouseRightDown(e) == true)
			{

				//-- checking for collison of the mouse --//

				if (BoundingBoxCol(Rect2D(mousePosition().x, mousePosition().y, 10, 10), Rect2D(tilePlaced[i][j]->mPosition.x, tilePlaced[i][j]->mPosition.y, 50, 50)))
				{

					//-- toggles the isItBlocked bool --//

					if (tilePlaced[i][j]->isItBlocked == false)
					{
						tilePlaced[i][j]->isItBlocked = true;
					}
					else
					{
						tilePlaced[i][j]->isItBlocked = false;
					}
				}
			}
			tilePlaced[i][j]->update();
		}
	}
}

void Level1::createRoute()
{

	Vector2D tempNode;
	tempNode = currentNode;

		//-- Calculating the current tiles pathValue --//
		

		//-- checking surroiunding blocks --//

		int positionOfsetY;
		int positionOfsetX;

		for (int i = 0; i < 3; i++)
		{
			if (i == 0) { positionOfsetY = -1; }
			if (i == 1) { positionOfsetY = 0 ; }
			if (i == 2) { positionOfsetY = 1 ; }
			for (int j = 0; j < 3; j++)
			{
				if (j == 0) { positionOfsetX = -1; }
				if (j == 1) { positionOfsetX = 0 ; }
				if (j == 2) { positionOfsetX = 1 ; }


				if(currentNode.y + positionOfsetY >= 0 && 
				   currentNode.x + positionOfsetX >= 0 && 
				   currentNode.y + positionOfsetY <= rows - 1 && 
				   currentNode.x + positionOfsetX <= coloms - 1)
				{
					//-- Calculating the currentVareations tiles pathValue --//
					tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue = 
					(tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.x - endPos.x) + (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.y - endPos.y);

					if (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue < tilePlaced[currentNode.y][currentNode.x]->pathFindingValue)
					{
						currentNode = Vector2D(0, 0);
						currentNode = Vector2D(positionOfsetX + tempNode.x, positionOfsetY + tempNode.y);
					}
				}

			}
		}

		cout << currentNode.x << " " <<  currentNode.y << endl;

		tilePlaced[currentNode.y][currentNode.x]->isItBlocked = true;

		return;
}
