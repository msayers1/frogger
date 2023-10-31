//
//  AnimatedObject.cpp
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-17.
//

#include "World.h"
#include "AnimatedObject.h"

using namespace earshooter;

AnimatedObject::AnimatedObject(float x, float y, float angle,
								 float vx, float vy, float spin)
	:	Object(x, y, angle),
		//
		vx_(vx),
		vy_(vy),
		spin_(spin)
{
}

AnimatedObject::AnimatedObject(const WorldPoint& pt, float angle, const Velocity& vel, float spin)
	:	Object(pt, angle),
		//
		vx_(vel.vx),
		vy_(vel.vy),
		spin_(spin)
{
}


void AnimatedObject::update(float dt)
{
	if (vx_ != 0.f)
		setX(getX() + vx_*dt);
	if (vy_ != 0.f)
		setY(getY() + vy_*dt);
	if (spin_ != 0.f)
		setAngle(getAngle() + spin_*dt);
		
	//	Temporary stuff:  Freeze motion if the object's origin reaches the edges
	//	of the world
	if (getX() < World::X_MIN || getX() > World::X_MAX ||
		getY() < World::Y_MIN || getY() > World::Y_MAX)
	{
		switch (World::worldType)
		{
			case WorldType::BOX_WORLD:
			if (getX() < World::X_MIN || getX() > World::X_MAX){
				if (getX() < World::X_MIN)
					setX(World::X_MIN);
				else
					setX(World::X_MAX);
				vx_ = -vx_;
			}
			if (getY() < World::Y_MIN || getY() > World::Y_MAX){
				if (getY() < World::Y_MIN)
					setY(World::Y_MIN);
				else
					setY(World::Y_MAX);
				vy_ = -vy_;
			}
			break;
			
			case WorldType::CYLINDER_WORLD:
				if (getX() < World::X_MIN)
					setX(getX() + World::WIDTH);
				else if (getX() > World::X_MAX)
					setX(getX() - World::WIDTH);
			if (getY() < World::Y_MIN || getY() > World::Y_MAX){
				if (getY() < World::Y_MIN)
					setY(World::Y_MIN);
				else
					setY(World::Y_MAX);
				vy_ = -vy_;
			}
			break;
			case WorldType::TORUS_WORLD:
				if (getX() < (World::X_MIN ))
					setX(getX() + World::WIDTH);
				else if (getX() > (World::X_MAX ))
					setX(getX() - World::WIDTH);
				if (getY() < (World::X_MIN ))
					setY(getY() + World::HEIGHT);
				else if (getY() > (World::Y_MAX ))
					setY(getY() - World::HEIGHT);
			    break;	
			default:
			break;
		}
	}
}
