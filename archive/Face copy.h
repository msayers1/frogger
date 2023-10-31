//
//  Ellipse.hpp
//  Prog 02
//
//  Created by Jean-Yves Hervé on 2023-09-14.
//

#ifndef FACE_H
#define FACE_H

#include "ComplexGraphicObject.h"
#include "Ellipse.h"

namespace earshooter
{
	class Face : public ComplexGraphicObject
	{
		private:
		

		public:
		
			Face(float centerX, float centerY);
			~Face() = default;
			
			//disabled constructors & operators
			Face() = delete;
			Face(const Face& obj) = delete;	// copy
			Face(Face&& obj) = delete;		// move
			Face& operator = (const Face& obj) = delete;	// copy operator
			Face& operator = (Face&& obj) = delete;			// move operator

			bool isInside(const WorldPoint& pt) const;

	};
}

#endif // FACE_H
