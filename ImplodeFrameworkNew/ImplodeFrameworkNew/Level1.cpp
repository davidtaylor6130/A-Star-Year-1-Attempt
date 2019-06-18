#include "Level1.h"
#include "Events.h"

Level1::Level1(SDL_Renderer* renderer) : GameScreen(renderer)
{
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

			if (isKeyDown(SDLK_SPACE, e) == true && KeyDown == false)
			{
				createRoute();
				KeyDown = true;
			}
			else if (KeyDown == true && isKeyUp(SDLK_SPACE, e) == true)
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
	//-- Veriable Declirations --//
		int smallestAStarAlgorithum = 9999999;

		Vector2D tempNode;
		tempNode = currentNode;

		int positionOfsetY = 0;
		int positionOfsetX = 0;

		int xDiffrence = 0;
		int yDiffrence = 0;
		int xyDiffrence = 0;

		//-- checking surroiunding blocks --//

		for (int i = 0; i < 3; i++)
		{
			if (i == 0) { positionOfsetY = -1; }
			if (i == 1) { positionOfsetY = 0; }
			if (i == 2) { positionOfsetY = 1; }
			for (int j = 0; j < 3; j++)
			{
				if (j == 0) { positionOfsetX = -1; }
				if (j == 1) { positionOfsetX = 0; }
				if (j == 2) { positionOfsetX = 1; }

				if (currentNode.y + positionOfsetY >= 0 &&
					currentNode.x + positionOfsetX >= 0 &&
					currentNode.y + positionOfsetY < rows - 1 &&
					currentNode.x + positionOfsetX < coloms - 1)
				{

					//-- Calculating the currentVareations tiles pathWeighting --//

					xDiffrence = tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.x - tilePlaced[endPos.y][endPos.x]->mPosition.x;
					yDiffrence = tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.y - tilePlaced[endPos.y][endPos.x]->mPosition.y;

					if (xDiffrence <= 0) { xDiffrence = abs(xDiffrence); }
					if (yDiffrence <= 0) { yDiffrence = abs(yDiffrence); }

					xyDiffrence = xDiffrence + yDiffrence;

					//-- setting the pathweighting --//
					if (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->isItBlocked == false)
					{
						tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue = xyDiffrence;
						tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->text->UpdateText(to_string(xyDiffrence).c_str());
					}
					else if (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->isItBlocked == true)
					{
						tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue = 99999999;
						tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->text->UpdateText(to_string(tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue).c_str());
					}

					//-- Checks to see is the node is lower than the current nodes --//
					if (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue < tilePlaced[currentNode.y][currentNode.x]->pathFindingValue)
					{

						//-- Checks to see if its lowest and if it is saves it --//
						if (smallestAStarAlgorithum > tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue &&
							tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->isItBlocked == false)
						{

							//-- for the pathing to work correctly it needs to be here is start position is above the end --//
							if (startPosition.x < endPosition.x && startPosition.y < endPosition.y)
							{
								smallestAStarAlgorithum = tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue;
							}

							//-- reset the current node position --//
							currentNode = Vector2D(0, 0);
							currentNode = Vector2D(positionOfsetX + tempNode.x, positionOfsetY + tempNode.y);

							//-- for the pathing to work correctly it needs to be here is start position is above the end --//
							if (startPosition.x > endPosition.x && startPosition.y > endPosition.y)
							{
								//-- stops errors of nullptr in the array --//
								if (currentNode.y + positionOfsetY > -1 && currentNode.x + positionOfsetX > -1)
									smallestAStarAlgorithum = tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue;
							}
						}
					}

					//-- DEBUGING --//

						//-- More Info --//

							//cout << endl;
							//cout << "Diffrence in x: " << (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.x - tilePlaced[endPos.y][endPos.x]->mPosition.x) << endl;
							//cout << "Diffrence in y: " << (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.y - tilePlaced[endPos.y][endPos.x]->mPosition.y) << endl;

							//cout << endl;
							//cout << "xDiffrence: " << xDiffrence << endl;
							//cout << "yDiffrence: " << yDiffrence << endl;

							//cout << endl;
							//cout << "calDiff: " << xyDiffrence << endl;
							//cout << "SavedDiff: " << tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue << endl;

						//-- Easy to read --//
							//cout << tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->pathFindingValue << " " ;
				}


			}
			//-- Easy to read --//
				//cout << endl;
		}


		//cout << (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.x - tilePlaced[endPos.y][endPos.x]->mPosition.x) << endl;
		//cout << (tilePlaced[currentNode.y + positionOfsetY][currentNode.x + positionOfsetX]->mPosition.y - tilePlaced[endPos.y][endPos.x]->mPosition.y) << endl;
		//cout << currentNode.x << " " <<  currentNode.y << endl;

		tilePlaced[currentNode.y][currentNode.x]->isItPath = true;
	
	return;
}
