// StaticBackground.h
#ifndef STATICBACKGROUND_H
#define STATICBACKGROUND_H

#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "Rectangle.h"

namespace earshooter
{
	class StaticBackground : public ComplexGraphicObject, public AnimatedObject
	{
		private:
		

		public:
			StaticBackground();
			~StaticBackground() = default;
			
			//disabled constructors & operators
			StaticBackground(const StaticBackground& obj) = delete;	// copy
			StaticBackground(StaticBackground&& obj) = delete;		// move
			StaticBackground& operator = (const StaticBackground& obj) = delete;	// copy operator
			StaticBackground& operator = (StaticBackground&& obj) = delete;			// move operator

	};

}

#endif // StaticBackground_H
