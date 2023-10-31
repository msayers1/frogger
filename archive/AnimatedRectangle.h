//
//  AnimatedRectangle.h
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-09.
//

#ifndef ANIMATED_RECTANGLE_H
#define ANIMATED_RECTANGLE_H

#include "Rectangle.h"
#include "AnimatedObject.h"

namespace earshooter
{
	class AnimatedRectangle : public Rectangle, public AnimatedObject
	{
		public:
		
			AnimatedRectangle(float centerX, float centerY, float angle, float width, float height,
							float vx, float vy, float spin, float r, float g, float b);
			AnimatedRectangle(const WorldPoint& pt, float angle, float width, float height,
							const Velocity& vel, float spin, float r, float g, float b);
			~AnimatedRectangle() = default;
			
			//disabled constructors & operators
			AnimatedRectangle() = delete;
			AnimatedRectangle(const AnimatedRectangle& obj) = delete;	// copy
			AnimatedRectangle(AnimatedRectangle&& obj) = delete;		// move
			AnimatedRectangle& operator = (const AnimatedRectangle& obj) = delete;	// copy operator
			AnimatedRectangle& operator = (AnimatedRectangle&& obj) = delete;		// move operator
	};
}

#endif //	ANIMATED_RECTANGLE_H
