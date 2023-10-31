//
//  SmilingFace.hpp
//  Week 08 - Earshooter

#ifndef SMILING_FACE_H
#define SMILING_FACE_H

#include <memory>
#include <vector>
#include "commonTypes.h"
#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "BoundingBox.h"

namespace earshooter {

	class SmilingFace : public GraphicObject, public AnimatedObject
	{

		public:

			/**    Default constructor: creates a face at a random position
			 *		and orientation, and with random color
			 */
			SmilingFace();

			/**	Creates a face with random position and orientation, and the
			 * specified color
			 * @PARAM fillColor the face's color
			 */
			SmilingFace(ColorIndex fillColor);

			/**	Creates a face with random position and orientation, and the
			 * specified color
			 * @PARAM red red component [0,1] of the face's color
			 * @PARAM green green component [0,1] of the face's color
			 * @PARAM blue blue component [0,1] of the face's color
			 */
			SmilingFace(float red, float green, float blue);

			/**	Creates a static smiling face object with the specified position,
			 * scale, and color
			 * @PARAM pt	coordinates of the face
			 * @PARAM angle	orientation of the face (in degree)
			 * @PARAM scale	scale factor to apply to the face, for rendering and collision detection
			 * @PARAM fillColor the face's color
			 */
			SmilingFace(const WorldPoint& pt, float angle, float scale,
						ColorIndex fillColor);

			/**	Creates a static smiling face object with the specified position,
			 * scale, and color
			 * @PARAM pt	coordinates of the face
			 * @PARAM angle	orientation of the face (in degree)
			 * @PARAM scale	scale factor to apply to the face, for rendering and collision detection
			 * @PARAM red red component [0,1] of the face's color
			 * @PARAM green green component [0,1] of the face's color
			 * @PARAM blue blue component [0,1] of the face's color
			 */
			SmilingFace(const WorldPoint& pt, float angle, float scale,
						float red, float green, float blue);

			/**	Creates a smiling face object with the specified position,
			 * velocity, scale, and color
			 * @PARAM pt	coordinates of the face
			 * @PARAM angle	orientation of the face (in degree)
			 * @PARAM vel	velocity of the face
			 * @PARAM spin	angular velocity of the face (in degree/s)
			 * @PARAM scale	scale factor to apply to the face, for rendering and collision detection
			 * @PARAM fillColor the face's color
			 */
			SmilingFace(const WorldPoint& pt, float angle,
						const Velocity& vel, float spin, float scale,
						ColorIndex fillColor);

			/**	Creates a smiling face object with the specified position,
			 * velocity, scale, and color
			 * @PARAM pt	coordinates of the face
			 * @PARAM angle	orientation of the face (in degree)
			 * @PARAM vel	velocity of the face
			 * @PARAM spin	angular velocity of the face (in degree/s)
			 * @PARAM scale	scale factor to apply to the face, for rendering and collision detection
			 * @PARAM red red component [0,1] of the face's color
			 * @PARAM green green component [0,1] of the face's color
			 * @PARAM blue blue component [0,1] of the face's color
			 */
			SmilingFace(const WorldPoint& pt, float angle,
						const Velocity& vel, float spin, float scale,
						float red, float green, float blue);
						

			/**	Destructor
			 */
			~SmilingFace();
		
			/** Determines whether a world point is inside the object
			 *	@PARAM pt	the point to check the status of
			 *	@RETURN		true if the point is inside (collides with) this object
			 */
			bool isInside(const WorldPoint& pt) const;

			/** Returns this faces's unique face creation index
			 *	@RETURN this face's unique face creation index
			 */
			unsigned int getIndex() const;
		

			/** Returns the number of smiling face objects currently in the
			 *  application.
			 *	@RETURN the number of active smiling face objects
			 */
			static unsigned int getLiveCounter(void);
			
			/**    Disabled copy constructor
			 * @PARAM obj    object to copy
			 */
			SmilingFace(const SmilingFace& obj) = delete;
		
			/**    Disabled move constructor
			 * @PARAM obj    object to move
			 */
			SmilingFace(SmilingFace&& obj) = delete;
		
			/**    Disabled copy operator
			 * @PARAM obj    object to copy
			 * @RETURN    reference to this object
			 */
			const SmilingFace& operator = (const SmilingFace& obj) = delete;
		
			/**    Disabled move operator
			 * @PARAM obj    object to move
			 * @RETURN    reference to this object
			 */
			SmilingFace& operator = (SmilingFace&& obj) = delete;
			
		protected:
		
			void draw_() const;
			
		private:
		
			/**	Counter of the number of SmilingFace objects created
			 */
			static unsigned int counter_;

			/**	Counter of the number of SmilingFace objects still "alive"
			 */
			static unsigned int liveCounter_;

			const static int LEFT_EAR;
			const static int RIGHT_EAR;
			const static int FACE;
			const static int HEAD;
			
			const static int HEAD_NUM_PARTS;
						
			const static float FACE_DIAMETER;
			const static float EAR_DIAMETER;
			const static float EYE_OUTER_DIAMETER;
			const static float EYE_INNER_DIAMETER;
			const static float MOUTH_V_DIAMETER;
			const static float MOUTH_H_DIAMETER;
			//
			const static float EAR_V_OFFSET;
			const static float EAR_H_OFFSET;
			const static float EYE_V_OFFSET;
			const static float EYE_H_OFFSET;
			const static float LEFT_EAR_X;
			const static float LEFT_EAR_Y;
			const static float RIGHT_EAR_X;
			const static float RIGHT_EAR_Y;
			//
			const static float LEFT_EYE_X;
			const static float LEFT_EYE_Y;
			const static float RIGHT_EYE_X;
			const static float RIGHT_EYE_Y;

			const static float MOUTH_H_OFFSET;
			const static float MOUTH_V_OFFSET;

			const static ColorIndex PART_BOX_COLOR[];
			
			/**	The face's scale
			 */
			float scale_;
			
			/**	 Filling color of the face
			 */
			float color_[4];
			
			/**	Unique face index (according to creation order) assigned to the object
			 */
			unsigned int index_;
			
			/**	Initializes the relative boxes' dimensions
			 */
			void initializeRelativeBox_() const;

			/**	Updates the relative boxes' dimensions
			 */
			void updateAbsoluteBox_() const;


	};
}

#endif //	SMILING_FACE_H
