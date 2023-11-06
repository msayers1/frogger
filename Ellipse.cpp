//
//  Ellipse.cpp
//
//  Created by Jean-Yves Hervé on 2023-09-14.
//

#include <cmath>
#include <iostream>
#include "glPlatform.h"
#include "Ellipse.h"

using namespace std;
using namespace earshooter;

const int Ellipse::numCirclePts_ = 24;
float** Ellipse::circlePts_;

bool ellipseInitialized = initEllipseFunc();

Ellipse::Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
				float red, float green, float blue)
	:	Object(centerX, centerY, angle),
		GraphicObject(centerX, centerY, angle),
		//
		radiusX_(radiusX),
		radiusY_(radiusY),
		red_(red),
		green_(green),
		blue_(blue)
{
	//	Just for giggles, I give a relative bounding box to my ellipse class.
	//	Completely unnecessary of course.
	setRelativeBoundingBox_(-radiusX, +radiusX, -radiusY, +radiusY);
}

Ellipse::Ellipse(const WorldPoint& pt, float angle, float radiusX, float radiusY,
				float red, float green, float blue)
	:	Object(pt, angle),
		GraphicObject(pt, angle),
		//
		radiusX_(radiusX),
		radiusY_(radiusY),
		red_(red),
		green_(green),
		blue_(blue)
{
	//	Just for giggles, I give a relative bounding box to my ellipse class.
	//	Completely unnecessary of course.
	setRelativeBoundingBox_(-radiusX, +radiusX, -radiusY, +radiusY);
}

Ellipse::Ellipse(float centerX, float centerY, float radius,
				float red, float green, float blue)
	:	Object(centerX, centerY, 0.f),
		GraphicObject(centerX, centerY, 0.f),
		//
		radiusX_(radius),
		radiusY_(radius),
		red_(red),
		green_(green),
		blue_(blue)
{
	//	Just for giggles, I give a relative bounding box to my ellipse class.
	//	Completely unnecessary of course.
	setRelativeBoundingBox_(-radius, +radius, -radius, +radius);
}

Ellipse::Ellipse(const WorldPoint& pt, float radius,
				float red, float green, float blue)
	:	Object(pt, 0.f),
		GraphicObject(pt, 0.f),
		//
		radiusX_(radius),
		radiusY_(radius),
		red_(red),
		green_(green),
		blue_(blue)
{
	//	Just for giggles, I give a relative bounding box to my ellipse class.
	//	Completely unnecessary of course.
	setRelativeBoundingBox_(-radius, +radius, -radius, +radius);
}

//Ellipse::~Ellipse()
//{
//	cout << "Ellipse at " << getX() << ", " << getY() << " saying goodbye" << endl;
//}

void Ellipse::draw_() const
{
	//	save the current coordinate system (origin, axes, scale)
	glPushMatrix();
	
	//	move to the center of the disk
	glTranslatef(getX(), getY(), 0.f);
		
	// apply rotation
	glRotatef(getAngle(), 0.f, 0.f, 1.f);
	
	//	apply the radius as a scale
	glScalef(radiusX_, radiusY_, 1.f);
	
	glColor3f(red_, green_, blue_);
	glBegin(GL_POLYGON);
			for (int k=0; k<numCirclePts_; k++)
				glVertex2f(circlePts_[k][0],
						   circlePts_[k][1]);
	glEnd();
	
	//	restore the original coordinate system (origin, axes, scale)
	glPopMatrix();
}

bool Ellipse::isInside(const WorldPoint& pt) const
{
	float dx = pt.x - getX(), dy = pt.y - getY();
	if (getAngle() != 0.f)
	{
		
		float ca = cosf(getAngle()), sa = sinf(getAngle());
		float rdx = (ca * dx + sa*dy)/radiusX_;
		float rdy = (-sa *dx + ca*dy)/radiusY_;
		// std::cout << "Inside Ellipse with Angle isInside: "  << (rdx*rdx + rdy*rdy < 1) << " | " << rdx << "," << rdy << " | " << radiusX_ << "," << radiusY_ << " | " << ca << "," << sa << " | " << pt.x << "," <<  pt.y << std::endl;
	
		return rdx*rdx + rdy*rdy < 1;
	
	}
	else
	{
		float dx = (pt.x - getX())/radiusX_, dy = (pt.y - getY())/radiusY_;
		
		// std::cout << "Inside Ellipse without Angle isInside: " << (dx*dx + dy*dy < 1) << " | " << getX() << "," << getY() << " | " << dx << "," << dy << " | " << " | " << radiusX_ << "," << radiusY_ << " | " << pt.x << "," <<  pt.y << std::endl;
		return dx*dx + dy*dy < 1;
	}
}

//	This one is not really needed, as the direct isInside test is more efficient.
void Ellipse::updateAbsoluteBox_() const
{
	float aRad = getAngleRad();
	float ca = cosf(aRad), sa = sinf(aRad);
	
	//	general case: the ellipse is not aligned with the world x & y axes
	if (ca != 0.f && sa != 0.f)
	{
		//	I could probably do it smarter/faster if I took the time to
		//	think about it, but I am being lazy :-)
		//	α is the current orientation angle of my ellipse, θ the curve's parameter [0, 2π]
		//	{x, y} = RotMatrix(α) . {radX * cos(θ), radY * sin(θ)}
		//		x = radX * cos(α) * cos(θ) - radY * sin(α) * sin(θ)
		//		y = radX * sin(α) * cos(θ) + radY * cos(a) * sin(θ)
		//
		//	I first compute the angles that correspond to extrema of the x and y coordinates,
		//	so, derivatives by θ are 0.
		//		x extremum:  -radX * cos(α) * sin(θ) - radY * sin(α) * cos(θ) == 0
		//						--> θ = atan(-tan(α) * radY/radX) + k.π
		//		y extremum:   - radX * sin(α) * sin(θ) + radY * cos(α) * cos(θ) == 0
		//						--> θ = atan(cot(α) * radY/radX) + k.π
		//	We remember that cos(atan(t)) = 1/√(1+t²) and sin(atan(t)) = t/√(1+t²)
		//	The +π just inverts sign for both.  So...
		float tanA = tanf(aRad), cotA = 1.f / tanA;
		float tx = -radiusY_/radiusX_ * tanA,
			  ty = +radiusY_/radiusX_ * cotA,
			  termTx = 1.f / sqrtf(1.f+tx*tx), termTy = 1.f / sqrtf(1.f+ty*ty);
		float ctx = termTx, stx = tx * termTx,
			  cty = termTy, sty = ty * termTy;
		float xExtr = radiusX_*ca*ctx - radiusY_*sa*stx;
		float yExtr = radiusX_*sa*cty + radiusY_*ca*sty;
		setAbsoluteBoundingBox_(-abs(xExtr), abs(xExtr), -abs(yExtr), abs(yExtr));
	
	}
	else if (sa == 0.f)
	{
		setAbsoluteBoundingBox_(-radiusX_, radiusX_, -radiusY_, radiusY_);
	}
	else
	{
		setAbsoluteBoundingBox_(-radiusY_, radiusY_, -radiusX_, radiusX_);
	}
}


//--------------------------------------
#if 0
#pragma mark Free functions
#endif
//--------------------------------------

void earshooter::drawDisk()
{
	glBegin(GL_POLYGON);
			for (int k=0; k<Ellipse::numCirclePts_; k++)
				glVertex2fv(Ellipse::circlePts_[k]);
	glEnd();
}

// I want this code to run only once
bool earshooter::initEllipseFunc()
{
	Ellipse::circlePts_ = new float*[Ellipse::numCirclePts_];
	for (int k=0; k<Ellipse::numCirclePts_; k++)
		Ellipse::circlePts_[k] = new float[2];
		
	//	Initialize the array of coordinates of the disk or radius 1 centered at (0, 0)
	float angleStep = 2.f*M_PI/Ellipse::numCirclePts_;
	for (int k=0; k<Ellipse::numCirclePts_; k++)
	{
		float theta = k*angleStep;
		Ellipse::circlePts_[k][0] = cosf(theta);
		Ellipse::circlePts_[k][1] = sinf(theta);
	}
	return true;
}

void earshooter::drawArc(float startFrac, float endFrac)
{
	if ((startFrac < endFrac) && (startFrac > -100) && (endFrac < +100))
	{
		int startIndex = static_cast<int>(roundf(startFrac*(Ellipse::numCirclePts_-1)));
		int endIndex = static_cast<int>(roundf(endFrac*(Ellipse::numCirclePts_-1)));
		
		glBegin(GL_LINE_STRIP);
			for (int k=startIndex; k<=endIndex; k++)
			{
				int index = k < 0 ? k + Ellipse::numCirclePts_ : k;
				glVertex2fv(Ellipse::circlePts_[index]);
			}
		glEnd();
	}
}

