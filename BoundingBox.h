//
//  BoundingBox.h
//  Week 08 - Earshooter

#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "commonTypes.h"
#include "World.h"

namespace earshooter
{
	class BoundingBox
	{
		private:
			float xmin_, xmax_, ymin_, ymax_;
			ColorIndex color_;
	
			static ColorIndex defaultColor_;
			
		public:
		
			/**	Creates a new bounding box at set dimensions and color.
			 *
			 * Note: Really should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param xmin	left bound of the box
			 * @param xmax	right bound of the box
			 * @param ymin	lower bound of the box
			 * @param ymax	upper bound of the box
			 * @param color	color of the box's contour
			 */
			BoundingBox(float xmin, float xmax, float ymin, float ymax,
						ColorIndex color = ColorIndex::NO_COLOR);

			/**	Creates a new bounding box at set dimensions and color.
			 *
			 * Note: Should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param cornerUL	upper-left corner of the box
			 * @param cornerLR	lower-right corner the box
			 * @param color	color of the box's contour
			 */
			BoundingBox(const WorldPoint& cornerUL, const WorldPoint& cornerLR,
						ColorIndex color = ColorIndex::NO_COLOR);

			/**	Creates an empty bounding box with the specified contour color
			 *
			 * @param color	color of the box's contour
			 */
			BoundingBox(ColorIndex color = ColorIndex::NO_COLOR);

			
			/** Sets a default color for all boxes that we assigned NO_COLOR
			 *
			 * @param color	color of the box's contour
			 */
			static void setDefaultColor(ColorIndex color);
			
			/**	Updates the box's position and dimensions
			 *
			 * Note: Should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param xmin	left bound of the box
			 * @param xmax	right bound of the box
			 * @param ymin	lower bound of the box
			 * @param ymax	upper bound of the box
			 */
			void setDimensions(float xmin, float xmax, float ymin, float ymax);


			/**	Updates the box's position and dimensions
			 *
			 * Note: Should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param cornerUL	upper-left corner of the box
			 * @param cornerLR	lower-right corner the box
			 */
			void setDimensions(const WorldPoint& cornerUL, const WorldPoint& cornerLR);


			/**	Set the boundig box's contour color.
			 *
			 * Note: Should verify that xmin ≤ xmax and ymin ≤ ymax
			 *  (but doesn't)
			 *
			 * @param color	color of the box's contour
			 */
			void setColor(ColorIndex color);


			/**	Returns the min value of the x coordinate
			 * @RETURN min value of the x coordinate
			 */
			inline float getXmin() const
			{
				return xmin_;
				
			}

			/**	Returns the min value of the x coordinate
			 * @RETURN min value of the x coordinate
			 */
			inline float getXmax() const
			{
				return xmax_;
			}

			/**	Returns the min value of the x coordinate
			 * @RETURN min value of the x coordinate
			 */
			inline float getYmin() const
			{
				return ymin_;
				
			}

			/**	Returns the min value of the x coordinate
			 * @RETURN min value of the x coordinate
			 */
			inline float getYmax() const
			{
				return ymax_;

			}

			/**	Returns the box's upper-left corner
			 * @RETURN the box's upper-left corner
			 */
			WorldPoint getCornerUL() const;
			
			/**	Returns the box's lower-right corner
			 * @RETURN the box's lower-right corner
			 */
			WorldPoint getCornerLR() const;
			

			/**	Checks whether a point is inside the box
			 * @PARAM x	horizontal coordinate of the point
			 * @PARAM y	vertical coordinate of the point
			 * @RETURN true if the point is inside the bounding box
			 */
			inline bool isInside(float x, float y) const
			{
				return ((x>=xmin_) && (x<=xmax_) && (y>=ymin_) && (y<=ymax_));
			}
		
			/** Renders the object
			 */
			void draw() const;
	};
}

#endif //	BOUNDING_BOX_H
