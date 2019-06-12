#pragma once
#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "structs.h"

#include <iostream>
using namespace std;

namespace Collisions
{
	bool BoundingBoxCol(Rect2D Rect1,Rect2D Rect2);
	bool CircleCollision(Rect2D rect1, Rect2D rect2, int radius1, int radius2);
}

#endif