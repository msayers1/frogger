// Car.h
#ifndef CAR_H
#define CAR_H

#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"

namespace earshooter
{
	enum CarNumber {	CAR_ONE = 1,
					CAR_TWO = 2,
					CAR_THREE = 3
	};
	// All will probably be slow but could add in the idea of levels. 
	enum CarSpeed {	CAR_BACK_SLOW = -1,
					CAR_BACK_MODERATE = -2,
					CAR_BACK_FAST = -3,
					CAR_SLOW = 1,
					CAR_MODERATE = 2,
					CAR_FAST = 3
	};

	class Car: public ComplexGraphicObject, public AnimatedObject
	{
		private:
		

		public:
			Car(CarNumber number, CarSpeed speed, float x, float y);
			~Car() = default;
			
			//disabled constructors & operators
			Car(const Car& obj) = delete;	// copy
			Car(Car&& obj) = delete;		// move
			Car& operator = (const Car& obj) = delete;	// copy operator
			Car& operator = (Car&& obj) = delete;			// move operator

	};
}
#endif // CAR_H



