//
//  BoundingBox.cpp
//  Week 08 - Earshooter

#include <cfloat>
#include "glPlatform.h"
#include "BoundingBox.h"

using namespace earshooter;

ColorIndex BoundingBox::defaultColor_ = ColorIndex::RED;

BoundingBox::BoundingBox(float xmin, float xmax, float ymin, float ymax,
						 ColorIndex color)
	: 	xmin_(xmin),
		xmax_(xmax),
		ymin_(ymin),
		ymax_(ymax),
		color_(color)
{
}

BoundingBox::BoundingBox(const WorldPoint& cornerUL, const WorldPoint& cornerLR,
						ColorIndex color)
	: 	xmin_(cornerUL.x),
		xmax_(cornerLR.x),
		ymin_(cornerUL.y),
		ymax_(cornerLR.y),
		color_(color)
{
}

BoundingBox::BoundingBox(ColorIndex color)
	: 	xmin_(FLT_MAX),
		xmax_(FLT_MAX),
		ymin_(FLT_MAX),
		ymax_(FLT_MAX),
		color_(color)
	{
	}


void BoundingBox::setDimensions(float xmin, float xmax, float ymin, float ymax)
{
	xmin_ = xmin;
	xmax_ = xmax;
	ymin_ = ymin;
	ymax_ = ymax;
}

void BoundingBox::setDimensions(const WorldPoint& cornerUL, const WorldPoint& cornerLR)
{
	xmin_ = cornerUL.x;
	xmax_ = cornerLR.x;
	ymin_ = cornerUL.y;
	ymax_ = cornerLR.y;
}

void BoundingBox::draw(void) const
{
//	glPushMatrix();
	if (color_ != ColorIndex::NO_COLOR)
	{
		glColor4fv(COLOR[static_cast<int>(color_)]);
	}
	else
	{
		glColor4fv(COLOR[static_cast<int>(defaultColor_)]);
	}
//	const GLfloat worldToPixel = World::getWorldToPixel();
//	glScalef(worldToPixel, worldToPixel, worldToPixel);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xmin_, ymin_);
		glVertex2f(xmax_, ymin_);
		glVertex2f(xmax_, ymax_);
		glVertex2f(xmin_, ymax_);
	glEnd();
//	glPopMatrix();
}

WorldPoint BoundingBox::getCornerUL(void) const
{
	WorldPoint pt = {xmin_, ymax_};
	return pt;
}
		
WorldPoint BoundingBox::getCornerLR(void) const
{
	WorldPoint pt = {xmax_, ymin_};
	return pt;
}

void BoundingBox::setColor(ColorIndex color)
{
	color_ = color;
}

void BoundingBox::setDefaultColor(ColorIndex color)
{
	defaultColor_ = color;
}
