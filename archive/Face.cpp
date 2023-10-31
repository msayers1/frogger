//
//  Ellipse.cpp
//

#include <iostream>
#include "glPlatform.h"
#include "Face.h"

using namespace std;
using namespace earshooter;

Face::Face(float centerX, float centerY)
	:	Object(centerX, centerY, 0.f),
		ComplexGraphicObject(centerX, centerY, 0)
{
	// left ear
	addPart(make_shared<Ellipse>(-1.1f, 0.5f, 0.f, 0.5f, 0.7f, 0.6f, 0.2f, 0.7f));
	//	right ear
	addPart(make_shared<Ellipse>(1.1f, 0.5f, 0.f, 0.5f, 0.7f, 0.6f, 0.2f, 0.7f));
	//	face proper
	addPart(make_shared<Ellipse>(0.f, 0.f, 0.f, 1.f, 2.f, 0.6f, 0.6f, 1.f));
	//	left eye
	addPart(make_shared<Ellipse>(-0.5f, 0.5f, 0.f, 0.2f, 0.2f, 1.f, 1.f, 1.f));
	addPart(make_shared<Ellipse>(-0.5f, 0.5f, 0.f, 0.1f, 0.1f, 0.2f, 0.2f, 0.8f));
	//	right  eye
	addPart(make_shared<Ellipse>(+0.5f, 0.5f, 0.f, 0.2f, 0.2f, 1.f, 1.f, 1.f));
	addPart(make_shared<Ellipse>(+0.5f, 0.5f, 0.f, 0.1f, 0.1f, 0.2f, 0.2f, 0.8f));
	//	mouth
	addPart(make_shared<Ellipse>(+0.0f, -0.6f, 0.f, 0.4f, 0.2f, 0.4f, 0.2f, 0.8f));
}

bool Face::isInside(const WorldPoint& pt) const
{
	return false;
}
