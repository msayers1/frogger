//
//  AnimatedObject.h
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-17.
//

#ifndef ANIMATED_OBJECT_H
#define ANIMATED_OBJECT_H

#include "Object.h"

namespace earshooter
{
	class AnimatedObject : public virtual Object
	{
		private:
		
			float velocity_, vx_, vy_, spin_;


		public:

			AnimatedObject(float x, float y, float angle, float vx, float vy, float spin);
			AnimatedObject(const WorldPoint& pt, float angle, const Velocity& vel, float spin);
			
			//disabled constructors & operators
			AnimatedObject() = delete;
			AnimatedObject(const AnimatedObject& obj) = delete;	// copy
			AnimatedObject(AnimatedObject&& obj) = delete;		// move
			AnimatedObject& operator = (const AnimatedObject& obj) = delete;	// copy operator
			AnimatedObject& operator = (AnimatedObject&& obj) = delete;		// move operator

			virtual void update(float dt);

			inline void setSpeed(float speed)
			{
				vx_ = speed;
				vy_ = speed;
			}
			// set velocity with speed and angle in radians. 
			inline float getVelocity()
			{
				
				return velocity_;
			}

			// set velocity with speed and angle in radians. 
			inline void setVelocity(float speed, float angle)
			{
				
				velocity_ = speed;
				vx_ = speed * cosf(angle);
				vy_ = speed * sinf(angle);
			}

			// set velocity with speed and angle in radians. 
			inline void setVelocityWithGraphicObjectAngle(float speed)
			{
				
				velocity_ = speed;
				vx_ = speed * cosf((getAngle() + 90)*(M_PI/180));
				// std::cout << "vx_" << vx_ << " | ";
				vy_ = speed * sinf((getAngle() + 90)*(M_PI/180));
				// std::cout << "vy_" << vy_ << std::endl;
			}

			inline float getSpeedX() const
			{
				return vx_;
			}
			
			inline void setSpeedX(float vx)
			{
				vx_ = vx;
			}

			inline float getSpeedY() const
			{
				return vy_;
			}

			inline void setSpeedY(float vy)
			{
				vy_ = vy;
			}

			inline float getSpin() const
			{
				return spin_;
			}

			inline void setSpin(float spin)
			{
				spin_ = spin;
			}

		
	};
}

#endif // ANIMATED_OBJECT_H
