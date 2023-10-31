//
//  Rectangle.h
//  Template Project
//
//  Created by Jean-Yves Hervé on 2023-10-12.
//


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GraphicObject.h"

namespace earshooter
{
	class Rectangle : public GraphicObject
	{
		private:
		
			float width_, height_;
			float red_, green_, blue_;
				
		protected:
				
			void updateAbsoluteBox_() const;
			void draw_() const;
			
		public:
		
			Rectangle(float centerX, float centerY, float angle, float width, float height,
					float r, float g, float b);
			Rectangle(const WorldPoint& pt, float angle, float width, float height,
					float r, float g, float b);
			~Rectangle() = default;
			
			void draw() const;
			
			//disabled constructors & operators
			Rectangle() = delete;
			Rectangle(const Rectangle& obj) = delete;	// copy
			Rectangle(Rectangle&& obj) = delete;		// move
			Rectangle& operator = (const Rectangle& obj) = delete;	// copy operator
			Rectangle& operator = (Rectangle&& obj) = delete;		// move operator

			bool isInside(const WorldPoint& pt) const;

			inline float getWidth() const
			{
				return width_;
			}
			
			inline float getHeight() const
			{
				return height_;
			}
	};
}

#endif // RECTANGLE_H
