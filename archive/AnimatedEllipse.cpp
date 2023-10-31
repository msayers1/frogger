//
//  AnimatedEllipse.cpp
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-09.
//

#include <cmath>
#include <iostream>
#include "glPlatform.h"
#include "World.h"
#include "AnimatedEllipse.h"

using namespace std;
using namespace earshooter;


AnimatedEllipse::AnimatedEllipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
								 float vx, float vy, float spin,
								 float red, float green, float blue)
	:	Object(centerX, centerY, 0.f),
		Ellipse(centerX, centerY, angle, radiusX, radiusY, red, green, blue),
		AnimatedObject(centerX, centerY, angle, vx, vy, spin)
{
}

AnimatedEllipse::AnimatedEllipse(const WorldPoint& pt, float angle, float radiusX, float radiusY,
								 const Velocity& vel, float spin,
								 float red, float green, float blue)
	:	Object(pt, 0.f),
		Ellipse(pt, angle, radiusX, radiusY, red, green, blue),
		AnimatedObject(pt, angle, vel, spin)
{
}

AnimatedEllipse::AnimatedEllipse(float centerX, float centerY, float radius,
								 float vx, float vy,
								 float red, float green, float blue)
	:	Object(centerX, centerY, 0.f),
		Ellipse(centerX, centerY, radius, red, green, blue),
		AnimatedObject(centerX, centerY, 0.f, vx, vy, 0.f)
{
}

AnimatedEllipse::AnimatedEllipse(const WorldPoint& pt, float radius,
								 const Velocity& vel,
								 float red, float green, float blue)
	:	Object(pt, 0.f),
		Ellipse(pt, radius, red, green, blue),
		AnimatedObject(pt, 0.f, vel, 0.f)
{
}


void AnimatedEllipse::update(float dt)
{
	AnimatedObject::update(dt);

	float newRed = getRed() + 0.1*dt;
	if (newRed <= 1.0f)
		setRed(newRed);
}
