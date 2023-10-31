//
//  AnimatedEllipse.h
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-09.
//

#ifndef ANIMATED_ELLIPSE_H
#define ANIMATED_ELLIPSE_H

#include "Ellipse.h"
#include "AnimatedObject.h"

namespace earshooter
{
	class AnimatedEllipse : public Ellipse, public AnimatedObject
	{
		public:
		
			AnimatedEllipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
							float vx, float vy, float spin, float r, float g, float b);
			AnimatedEllipse(const WorldPoint& pt, float angle, float radiusX, float radiusY,
							const Velocity& vel, float spin, float r, float g, float b);
			AnimatedEllipse(float centerX, float centerY, float radius, float vx, float vy,
					float r, float g, float b);
			AnimatedEllipse(const WorldPoint& pt, float radius, const Velocity& vel,
					float r, float g, float b);
			~AnimatedEllipse() = default;
			
			//disabled constructors & operators
			AnimatedEllipse() = delete;
			AnimatedEllipse(const AnimatedEllipse& obj) = delete;	// copy
			AnimatedEllipse(AnimatedEllipse&& obj) = delete;		// move
			AnimatedEllipse& operator = (const AnimatedEllipse& obj) = delete;	// copy operator
			AnimatedEllipse& operator = (AnimatedEllipse&& obj) = delete;		// move operator
			
			void update(float dt);
			
	};
}

#endif //	ANIMATED_ELLIPSE_H
