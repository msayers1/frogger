// Turtle.h
#ifndef TURTLE_H
#define TURTLE_H

#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"

namespace earshooter
{
	enum TurtleNumber {	ONE = 1,
					TWO = 2,
					THREE = 3
	};
	// All will probably be slow but could add in the idea of levels. 
	enum TurtleSpeed {	TURTLE_BACK_SLOW = -1,
					TURTLE_BACK_MODERATE = -2,
					TURTLE_BACK_FAST = -3,
					TURTLE_SLOW = 1,
					TURTLE_MODERATE = 2,
					TURTLE_FAST = 3
	};

	class Turtle: public ComplexGraphicObject, public AnimatedObject
	{
		private:
		

		public:
			Turtle(TurtleNumber number, TurtleSpeed speed, float x, float y);
			~Turtle() = default;
			
			//disabled constructors & operators
			Turtle(const Turtle& obj) = delete;	// copy
			Turtle(Turtle&& obj) = delete;		// move
			Turtle& operator = (const Turtle& obj) = delete;	// copy operator
			Turtle& operator = (Turtle&& obj) = delete;			// move operator

	};
}
#endif // TURTLE_H



