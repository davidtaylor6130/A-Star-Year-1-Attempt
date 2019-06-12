#include "Collisions.h"

bool Collisions::BoundingBoxCol(Rect2D rect1, Rect2D rect2)
{
	int right1 = rect1.x + rect1.width; //the top of the first box
	int right2 = rect2.x + rect2.width; //top of the second box

	int bottom1 = rect1.y + rect1.height; //left of first box
	int bottom2 = rect2.y + rect2.height; //left of second box

	if ((right1 >= rect2.x) && (rect1.x <= right2) && //is right of first >= left of second but left of first !> right of second?
		(bottom1 >= rect2.y) &&(rect1.y <= bottom2)) //is bottom of first >= top of second but top of first !> bottom of second?
	{
		return true;
	}
	else
	{
		return false;
	}

	cout << "Failed to calculate bounding box collision ERROR CODE: 1.0.0" << endl;

return false;
}

bool Collisions::CircleCollision(Rect2D rect1, Rect2D rect2, int radius1, int radius2)
{
	Vector2D vec = Vector2D((rect1.x - rect2.x), (rect1.y - rect2.y)); //vector calculated for two objects
	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));

	double combinedDistance = radius1 + radius2; //Take the combined distance 

	return distance < combinedDistance; //if the distance is less than the combined distance then we have a collision
}