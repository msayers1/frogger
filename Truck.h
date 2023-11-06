// Truck.h
#ifndef TRUCK_H
#define TRUCK_H

#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"

namespace earshooter
{
	enum TruckSize {	TRUCK_SMALL = 1,
					TRUCK_MEDIUM = 2,
					TRUCK_LARGE = 3
	};
	// All will probably be slow but could add in the idea of levels. 
	enum TruckSpeed {	TRUCK_BACK_SLOW = -1,
					TRUCK_BACK_MODERATE = -2,
					TRUCK_BACK_FAST = -3,
					TRUCK_SLOW = 1,
					TRUCK_MODERATE = 2,
					TRUCK_FAST = 3
	};

	class Truck : public ComplexGraphicObject, public AnimatedObject
	{
		private:
		

		public:
			Truck(TruckSize size, TruckSpeed speed, float x, float y);
			~Truck() = default;
			
			//disabled constructors & operators
			Truck(const Truck& obj) = delete;	// copy
			Truck(Truck&& obj) = delete;		// move
			Truck& operator = (const Truck& obj) = delete;	// copy operator
			Truck& operator = (Truck&& obj) = delete;			// move operator

	};
}
#endif // TRUCK_H
