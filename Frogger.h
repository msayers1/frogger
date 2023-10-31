// Frogger.h
#ifndef Frogger_H
#define Frogger_H

#include "ComplexGraphicObject.h"
// #include "AnimatedObject.h"
#include "Rectangle.h"

namespace earshooter
{
	class Frogger : public ComplexGraphicObject
	{
		private:


		public:
			Frogger();
			~Frogger() = default;
			
			//disabled constructors & operators
			Frogger(const Frogger& obj) = delete;	// copy
			Frogger(Frogger&& obj) = delete;		// move
			Frogger& operator = (const Frogger& obj) = delete;	// copy operator
			Frogger& operator = (Frogger&& obj) = delete;			// move operator

	};
}
#endif // Frogger_H
