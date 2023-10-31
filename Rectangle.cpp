//
//  Rectangle.cpp
//
//  Created by Jean-Yves Hervé on 2023-09-14.
//

#include <cmath>
#include <iostream>
#include "glPlatform.h"
#include "Rectangle.h"

using namespace std;
using namespace earshooter;

Rectangle::Rectangle(float centerX, float centerY, float angle, float width, float height,
				float red, float green, float blue)
	:	Object(centerX, centerY, angle),
		GraphicObject(centerX, centerY, angle),
		//
		width_(width),
		height_(height),
		red_(red),
		green_(green),
		blue_(blue)
{
	//	Just for giggles, I give a relative bounding box to my rectangle class.
	//	Completely unnecessary of course.
	setRelativeBoundingBox_(-width/2, +width/2, -height/2, +height/2);
}

Rectangle::Rectangle(const WorldPoint& pt, float angle, float width, float height,
				float red, float green, float blue)
	:	Object(pt, angle),
		GraphicObject(pt, angle),
		//
		width_(width),
		height_(height),
		red_(red),
		green_(green),
		blue_(blue)
{
	//	Just for giggles, I give a relative bounding box to my rectangle class.
	//	Completely unnecessary of course.
	setRelativeBoundingBox_(-width/2, +width/2, -height/2, +height/2);
}

void Rectangle::draw_() const
{
	//	save the current coordinate system (origin, axes, scale)
	glPushMatrix();
	
	//	move to the center of the disk
	glTranslatef(getX(), getY(), 0.f);
		
	// apply rotation
	glRotatef(getAngle(), 0.f, 0.f, 1.f);
	
	//	apply the radius as a scale
	glScalef(width_, height_, 1.f);
	
	glColor3f(red_, green_, blue_);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(+0.5f, -0.5f);
		glVertex2f(+0.5f, +0.5f);
		glVertex2f(-0.5f, +0.5f);
	glEnd();
	
	//	restore the original coordinate system (origin, axes, scale)
	glPopMatrix();
}

bool Rectangle::isInside(const WorldPoint& pt) const
{
	float dx = pt.x - getX(), dy = pt.y - getY();
	if (getAngle() != 0.f)
	{
		float ca = cosf(getAngle()), sa = sinf(getAngle());
		float rdx = ca * dx + sa*dy;
		float rdy = -sa *dx + ca*dy;
		std::cout << "Inside Rectangle with Angle isInside: " << ((rdx >= -width_/2 ) && (rdx <= width_/2 ) &&
			   (rdy >= -height_/2 ) && (rdy <= +height_/2 )) << " | " << rdx << "," << rdy << " | " << width_ << "," << height_ << " | " << ca << "," << sa << " | " << pt.x << "," <<  pt.y << std::endl;
	
		return (rdx >= -width_/2 ) && (rdx <= width_/2 ) &&
			   (rdy >= -height_/2 ) && (rdy <= +height_/2 );
	
	}
	else
		std::cout << "Inside Rectangle without Angle isInside: " << ((pt.x >= getX() - width_/2 ) && (pt.x <= getX() + width_/2 ) &&
			   (pt.y >= getY() - height_/2 ) && (pt.y <= getY() + height_/2 )) << " | " << getX() << "," << getY() << " | " << width_ << "," << height_ << " | " << pt.x << "," <<  pt.y << std::endl;
		return (pt.x >= getX() - width_/2 ) && (pt.x <= getX() + width_/2 ) &&
			   (pt.y >= getY() - height_/2 ) && (pt.y <= getY() + height_/2 );
}


void Rectangle::updateAbsoluteBox_() const
{
	//	I could probably do it smarter/faster if I took the time to
	//	think about it, but I am being lazy :-)
	float ca = cosf(getAngleRad()), sa = sinf(getAngleRad());
	float x1 = +0.5f * (ca*width_ + sa*height_),
		  x2 = +0.5f * (ca*width_ - sa*height_),
		  x3 = -x1,
		  x4 = -x2;
	float y1 = +0.5f * (sa*width_ + ca*height_),
		  y2 = +0.5f * (sa*width_ - ca*height_),
		  y3 = -y1,
		  y4 = -y2;
	setAbsoluteBoundingBox_(min(min(min(x1, x2), x3), x4), max(max(max(x1, x2), x3), x4),
							min(min(min(y1, y2), y3), y4), max(max(max(y1, y2), y3), y4));
}
