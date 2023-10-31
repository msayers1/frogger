//
//  Object.h
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-17.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "World.h"

#define DEG_TO_RAD	0.017453293f

namespace earshooter
{
	class Object
	{
		private:
		
			float x_ , y_, angle_;
			int index_;
			static int count_;

		public:
		
			Object(float x, float y, float angle);
			Object(const WorldPoint& pt, float angle);
			
			//	The rule of thumb is:  If your class contains at least one virtual
			//	method (which indicates that it may be used polymorphically), then
			//	its destructor should be virtual
			virtual ~Object()
			{
				#if REPORT_DESTRUCT
					std::cout << "Object #" << index_ << " destructed" << std::endl;
				#endif
			}
			
			//disabled constructors & operators
			Object() = delete;
			Object(const Object& obj) = delete;	// copy
			Object(Object&& obj) = delete;		// move
			Object& operator = (const Object& obj) = delete;	// copy operator
			Object& operator = (Object&& obj) = delete;		// move operator

			inline float getX() const
			{
				return x_;
			}
			
			inline void setX(float x)
			{
				x_ = x;
			}

			inline float getY() const
			{
				return y_;
			}

			inline void setY(float y)
			{
				y_ = y;
			}

			inline float getAngle() const
			{
				return angle_;
			}

			inline float getAngleRad() const
			{
				return angle_ * DEG_TO_RAD;
			}

			inline void setAngle(float angle)
			{
				angle_ = angle;
			}
			inline int getIndex() const
			{
				return index_;
			}
	};
}

#endif //	OBJECT_H
