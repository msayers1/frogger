//
//  GraphicObject.h
//
//  Created by Jean-Yves Hervé on 2023-10-05.
//

#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H

#include <memory>
#include "World.h"
#include "Object.h"
#include "BoundingBox.h"

namespace earshooter
{
	class GraphicObject	: public virtual Object	// abstract class
	{
		private:
		
			/**	The object's relative bounding box
			 */
			mutable std::shared_ptr<BoundingBox> relativeBox_;

			/**	The object's absolute bounding box
			 */
			mutable std::shared_ptr<BoundingBox> absoluteBox_;
			
			
	

			/** If true, then all graphic objects with an absolute bounding box
				will display it.  Cannot be true simultaneously with drawRelativeBoxes_
			 */
			static bool drawAbsoluteBoxes_;

			/** If true, then all graphic objects with a relative bounding box
				will display it.  Cannot be true simultaneously with drawAbsoluteBoxes_
			 */
			static bool drawRelativeBoxes_;
		
		protected:
		
			/**	Set the absolute box's dimensions
			 *
			 * Note: Really should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param xmin	left bound of the box
			 * @param xmax	right bound of the box
			 * @param ymin	lower bound of the box
			 * @param ymax	upper bound of the box
			 */
			void setAbsoluteBoundingBox_(float xmin, float xmax, float ymin, float ymax) const ;

			/**	Set the absolute box's dimensions
			 *
			 * Note: Should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param cornerUL	upper-left corner of the box
			 * @param cornerLR	lower-right corner the box
			 */
			void setAbsoluteBoundingBox_(const WorldPoint& cornerUL, const WorldPoint& cornerLR) const ;

			/**	Set the relative box's dimensions
			 *
			 * Note: Really should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param xmin	left bound of the box
			 * @param xmax	right bound of the box
			 * @param ymin	lower bound of the box
			 * @param ymax	upper bound of the box
			 */
			void setRelativeBoundingBox_(float xmin, float xmax, float ymin, float ymax) const ;

			/**	Set the relative box's dimensions
			 *
			 * Note: Should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param cornerUL	upper-left corner of the box
			 * @param cornerLR	lower-right corner the box
			 */
			void setRelativeBoundingBox_(const WorldPoint& cornerUL, const WorldPoint& cornerLR) const ;

			/**	Sets the absolute bounding box's contour color
			 *
			 * @param color	color of the box's contour
			 */
			void setAbsoluteBoundingBoxColor_(ColorIndex color) const ;

			/**	Sets the relative bounding box's contour color
			 *
			 * @param color	color of the box's contour
			 */
			void setRelativeBoundingBoxColor_(ColorIndex color) const ;


			virtual void updateAbsoluteBox_() const
			{}


			/** The drawing function that subclasses must implement.
			 */
			virtual void draw_() const = 0;
			
		public:
		
			GraphicObject(const WorldPoint& pt, float angle);
			
			GraphicObject(float x, float y, float angle);

			//	The rule of thumb is:  If your class contains at least one virtual
			//	method (which indicates that it may be used polymorphically), then
			//	its destructor should be virtual
			virtual ~GraphicObject() = default;
			
			//disabled constructors & operators
			GraphicObject() = delete;
			GraphicObject(const GraphicObject& obj) = delete;	// copy
			GraphicObject(GraphicObject&& obj) = delete;		// move
			GraphicObject& operator = (const GraphicObject& obj) = delete;	// copy operator
			GraphicObject& operator = (GraphicObject&& obj) = delete;		// move operator
	
			//	not virtual anymore
			void draw() const;

			
			virtual bool isInside(const WorldPoint& pt) const = 0;
			
			virtual const std::shared_ptr<BoundingBox> getRelativeBox() const
			{
				return relativeBox_;
			}
			
			virtual const std::shared_ptr<BoundingBox> getAbsoluteBox() const;
			
			static inline void drawAbsoluteBoxes(bool drawBoxes)
			{
				drawAbsoluteBoxes_ = drawBoxes;
				if (drawBoxes)
				{
					drawRelativeBoxes_ = false;
				}
			}

			static inline void drawRelativeBoxes(bool drawBoxes)
			{
				drawRelativeBoxes_ = drawBoxes;
				if (drawBoxes)
				{
					drawAbsoluteBoxes_ = false;
				}
			}

			static inline bool absoluteBoxesAreDrawn()
			{
				return drawAbsoluteBoxes_;
			}

			static inline bool relativeBoxesAreDrawn()
			{
				return drawRelativeBoxes_;
			}

	};
}

#endif // GRAPHIC_OBJECT_H 
