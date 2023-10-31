//
//  ComplexGraphicObject.cpp
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-05.
//

#include <stdio.h>

#include <cmath>
#include <iostream>
#include "glPlatform.h"
#include "ComplexGraphicObject.h"

using namespace std;
using namespace earshooter;

ComplexGraphicObject::ComplexGraphicObject(const WorldPoint& pt, float angle)
	:	Object(pt, angle),
		GraphicObject(pt, angle)
{
}
ComplexGraphicObject::ComplexGraphicObject(float x, float y, float angle)
	:	Object(x, y, angle),
		GraphicObject(x, y, angle)
{
}

void ComplexGraphicObject::addPart(shared_ptr<GraphicObject> part)
{
	partList_.push_back(part);
}


void ComplexGraphicObject::draw_() const
{
	//	save the current coordinate system (origin, axes, scale)
	glPushMatrix();
	
	//	move to the center of the disk
	glTranslatef(getX(), getY(), 0.f);
	glRotatef(getAngle(), 0.f, 0.f, 1.f);
		
	for (auto obj : partList_)
		obj->draw();
		
	//	restore the original coordinate system (origin, axes, scale)
	glPopMatrix();
}

bool ComplexGraphicObject::isInside(const WorldPoint& pt) const
{
	bool check = false;
	std::cout << "Inside Complex Graphic Object isInside: " <<  pt.x << "," <<  pt.y << " | " <<  getX() << "," <<  getY() << std::endl;
	WorldPoint localPt = {(pt.x - getX()), pt.y - getY()};
	// return false;
	for (auto obj : partList_)
		check = check || obj->isInside(localPt);
	return check;
}
