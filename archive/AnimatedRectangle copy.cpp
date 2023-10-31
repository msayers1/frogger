//
//  AnimatedRectangle.cpp
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-09.
//

#include <cmath>
#include <iostream>
#include <algorithm>
#include "glPlatform.h"
#include "World.h"
#include "AnimatedRectangle.h"

using namespace std;
using namespace earshooter;

AnimatedRectangle::AnimatedRectangle(float centerX, float centerY, float angle,
								 float width, float height,
								 float vx, float vy, float spin,
								 float red, float green, float blue)
	:	Object(centerX, centerY, angle),
		Rectangle(centerX, centerY, angle, width, height, red, green, blue),
		AnimatedObject(centerX, centerY, angle, vx, vy, spin)
{
}

AnimatedRectangle::AnimatedRectangle(const WorldPoint& pt, float angle,
								 float width, float height,
								 const Velocity& vel, float spin,
								 float red, float green, float blue)
	:	Object(pt, angle),
		Rectangle(pt, angle, width, height, red, green, blue),
		AnimatedObject(pt, angle, vel, spin)
{
}
