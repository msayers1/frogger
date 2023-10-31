// Log.h
#ifndef LOG_H
#define LOG_H

#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"

namespace earshooter
{
	enum LogSize {	SMALL = 1,
					MEDIUM = 2,
					LARGE = 3
	};
	// All will probably be slow but could add in the idea of levels. 
	enum LogSpeed {	BACK_SLOW = -1,
					BACK_MODERATE = -2,
					BACK_FAST = -3,
					SLOW = 1,
					MODERATE = 2,
					FAST = 3
	};

	class Log : public ComplexGraphicObject, public AnimatedObject
	{
		private:
		

		public:
			Log(LogSize size, LogSpeed speed, float x, float y);
			~Log() = default;
			
			//disabled constructors & operators
			Log(const Log& obj) = delete;	// copy
			Log(Log&& obj) = delete;		// move
			Log& operator = (const Log& obj) = delete;	// copy operator
			Log& operator = (Log&& obj) = delete;			// move operator

	};
}
#endif // LOG_H
