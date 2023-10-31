//
//  ComplexGraphicObject.h
//
//  Created by Jean-Yves Hervé on 2023-10-05.
//

#ifndef COMPLEX_GRAPHIC_OBJECT_H
#define COMPLEX_GRAPHIC_OBJECT_H

#include <memory>
#include <vector>
//
#include "GraphicObject.h"

namespace earshooter
{
	class ComplexGraphicObject : public GraphicObject
	{
		private:
		
			std::vector< std::shared_ptr<GraphicObject> > partList_;

		protected:
		
			//	Here, this class implements default behavior (draw all parts),
			//	but there may be a subclass that needs to do something different
			virtual void draw_() const;
			

		public:
		
			ComplexGraphicObject(float centerX, float centerY, float angle);

			ComplexGraphicObject(const WorldPoint& pt, float angle);

			virtual ~ComplexGraphicObject() = default;
			

			void addPart(std::shared_ptr<GraphicObject> part);

			//disabled constructors & operators
			ComplexGraphicObject() = delete;
			ComplexGraphicObject(const ComplexGraphicObject& obj) = delete;	// copy
			ComplexGraphicObject(ComplexGraphicObject&& obj) = delete;		// move
			ComplexGraphicObject& operator = (const ComplexGraphicObject& obj) = delete;	// copy operator
			ComplexGraphicObject& operator = (ComplexGraphicObject&& obj) = delete;		// move operator

			bool isInside(const WorldPoint& pt) const;

	};
}

#endif //	COMPLEX_GRAPHIC_OBJECT_H
