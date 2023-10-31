//
//  Ellipse.hpp
//
//  Created by Jean-Yves Hervé on 2023-09-14.
//

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "GraphicObject.h"

namespace earshooter
{
	class Ellipse : public GraphicObject
	{
		friend bool initEllipseFunc();
		friend void drawDisk();
		friend void drawArc(float startFrac, float endFrac);
		
		private:
		
			float radiusX_, radiusY_;
			float red_, green_, blue_;
				
			static const int numCirclePts_;
			static float** circlePts_;

		protected:
		
			void draw_() const;
			void updateAbsoluteBox_() const;			

		public:
		
			Ellipse(float centerX, float centerY, float angle, float radiusX, float radiusY,
					float r, float g, float b);
			Ellipse(const WorldPoint& pt, float angle, float radiusX, float radiusY,
					float r, float g, float b);
			Ellipse(float centerX, float centerY, float radius,
					float r, float g, float b);
			Ellipse(const WorldPoint& pt, float radius,
					float r, float g, float b);
			~Ellipse() = default;
			

			//disabled constructors & operators
			Ellipse() = delete;
			Ellipse(const Ellipse& obj) = delete;	// copy
			Ellipse(Ellipse&& obj) = delete;		// move
			Ellipse& operator = (const Ellipse& obj) = delete;	// copy operator
			Ellipse& operator = (Ellipse&& obj) = delete;		// move operator
			
			inline float getRed() const {
				return red_;
			}
			inline void setRed(float red) {
				// check red in range
				red_ = red;
			}

			bool isInside(const WorldPoint& pt) const;

	};

	bool initEllipseFunc();
	void drawDisk();
	void drawArc(float startFrac, float endFrac);
}

#endif // ELLIPSE_H
