//
//   Polygon.cpp
//   Prog01Version1
//
//   
//  Hope for being able to do different polygons. 
//
//   Created by Michael Sayers on 9/22/2023 
//   Modified from Class Code Examples from CS406 Jean-Yves Hervé
//

#include <cmath>
#include <vector>
#include <utility>
#include <iostream>
#include "glPlatform.h"
#include "Polygon.h"

using namespace std;
using namespace earshooter;

//Basic sequence of vertices to create a polygon. 
Polygon::Polygon(float centerX, float centerY, float angle, float scaleX, float scaleY,std::vector<std::pair<float,float>> vertexVector,
				float red, float green, float blue)
	:	GraphicObject(centerX, centerY, angle),
		Object(centerX,centerY,angle),
		_scaleX(scaleX),
		_scaleY(scaleY),
        _vertexVector(vertexVector),
		_red(red),
		_green(green),
		_blue(blue)
{
}
//Implementiation of different shapes like lines. 
// Polygon::Polygon(float centerX, float centerY, float angle, float scaleX, float scaleY,std::vector<std::pair<float,float>> vertexVector,
// 				float red, float green, float blue, int type, float thickness)
// 	:	GraphicObject(centerX, centerY, angle),
// 		_red(red), 
// 		_green(green), 
// 		_blue(blue),
//         _vertexVector(vertexVector),
//         _type(type),
//         _thickness(thickness),
//         _modification(sqrt(pow(thickness,2)/2))
// {
// }
Polygon::~Polygon()
{

}

void Polygon::draw() const
{
	//	save the current coordinate system (origin, axes, scale)
	glPushMatrix();
	
	//	move to the center of the disk
	glTranslatef(getX(), getY(), 0.f);
		
	// apply rotation
	glRotatef(getAngle(), 0.f, 0.f, 1.f);
	
	//	apply the  scale
	// glScalef(getScaleX(), getScaleY(), 1.f);
	glScalef(_scaleX, _scaleY, 1.f);
	
	glColor3f(_red, _green, _blue);
	glBegin(GL_POLYGON);
			for (int k=0; k<_vertexVector.size(); k++)
				glVertex2f(_vertexVector[k].first,
						   _vertexVector[k].second);
	glEnd();
	
	//	restore the original coordinate system (origin, axes, scale)
	glPopMatrix();
}

// Next thing to work on expanding a line to a polygon. 
// void Polygon::coordinateDraw() const
// {
	
// 	for (int j=0; j<((_vertexVector.size())-1); j++) {
//         //Math to consider the four corners of the box. 
//         std::vector<std::pair<float,float>> tempVector;
//         tempVector.push_back({_vertexVector[j].first-_})
//         glBegin(GL_POLYGON);
//                 for (int k=0; k<4; k++)
//                     glVertex2f(tempVector[k].first,
//                             tempVector[k].second);
//         glEnd();
//     };
// 	//	restore the original coordinate system (origin, axes, scale)
// 	glPopMatrix();
// }