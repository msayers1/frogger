#ifndef WORLD_H
#define WORLD_H

#include <random>
#include <cmath>
#include "commonTypes.h"

namespace earshooter {

	/** Essentially a set of application-wide global variables defining the
	 * dimensions of the "world" and the conversion factors from pixel to world
	 * units and back, as well as a few rendering constants.
	 *
	 */
	struct World {
		/**	Starting point for Frogger.
		 *	@see setWorldBounds
		 */
		static float froggerStartHeight;

		/** Static Background Variables
		 * 
		 */
		static int numLowerHedges;
		static float bottomTopHedgeHeight, topScoreAreaHeight, waterHeight, waterY, topHedgeHeight, topHedgeY, lowerHedgeHeight, lowerHedgeWidth, offsetLowerHedge, lowerHedgeX, lowerHedgeY, middleHedgeHeight, middleHedgeY, roadHeight, bottomScoreArea;
			
		/**	Minimum x value to get mapped to the display area.
		 *	Set in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static const float X_MIN;

		/**	Maximum x value to get mapped to the display area.
		 *	Set in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static const float X_MAX;

		/**	Minimum y value to get mapped to the display area.
		 *	Set in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static const float Y_MIN;

		/**	Maximum x value to get mapped to the display area.
		 *	Set in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static const float Y_MAX;

		/**	Calculated as X_MAX-X_MIN in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static const float WIDTH;

		/**	Calculated as Y_MAX-Y_MIN in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static const float HEIGHT;

		/**	Scaling factor converting pixel units to world units.
		 *	Calculated in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static float pixelToWorldRatio;

		/**	Scaling factor converting world units to pixel units.
		 *	Calculated in the main program by a call to setWorldBounds.
		 *	@see setWorldBounds
		 */
		static float worldToPixelRatio;
		
		/**	This one is really equal to pixelToWorldRatio, but it looks confusing
		 *	to write glSCalef(pixelToWorldRatio, pixelToWorldRatio, 1.f);
		 *	right before trying to drawe in pixel units.
		 *	@see setWorldBounds
		 */
		static float drawInPixelScale;
		
		static WorldType worldType;

		// Flag to show status of showing Reference frames. 
		static bool showReferenceFrames;
		/** Function called through the initialization of a global variable in the
		 *	main program.  Although the user specifies dimensions for the rendering pane,
		 *	the function may set different values that agree better with the world
		 *	aspect ratio.
		 * @param paneWidth		user-set width of the redering pane
		 * @param paneHeight	user-set height of the redering pane
		 */
		static void setScalingRatios(int& paneWidth, int& paneHeight);


		static std::random_device randDev;
		static std::default_random_engine randEngine;
		//
		static std::uniform_real_distribution<float> wxDist;
		static std::uniform_real_distribution<float> wyDist;
		static std::uniform_real_distribution<float> objectScaleDist;
		static std::uniform_real_distribution<float> colorDist;
		static std::uniform_real_distribution<float> normalDist;
		static std::uniform_real_distribution<float> angleDegDist;
		static std::uniform_real_distribution<float> angleRadDist;
		static std::uniform_real_distribution<float> velocityDist;
		static std::uniform_real_distribution<float> spinDegDist;
		static std::bernoulli_distribution animatedChoiceDist;
		static std::bernoulli_distribution headsOrTailsDist;
		static std::uniform_real_distribution<float> radiusDist;


	};

	WorldPoint pixelToWorld(float ix, float iy);
	PixelPoint worldToPixel(float wx, float wy);
	WorldPoint pixelToWorld(const PixelPoint& pt);
	PixelPoint worldToPixel(const WorldPoint& pt);
	
	inline WorldPoint randomWorldPoint()
	{
		return WorldPoint{ World::wxDist(World::randEngine),
						   World::wyDist(World::randEngine)};
	}
	inline float randomAngleDeg()
	{
		return World::angleDegDist(World::randEngine);
	}
	inline float randomAngleRad()
	{
		return World::angleRadDist(World::randEngine);
	}
	inline float randomObjectScale()
	{
		return World::objectScaleDist(World::randEngine);
	}
	inline float randomSpinDeg()
	{
		return World::spinDegDist(World::randEngine) *
				(World::headsOrTailsDist(World::randEngine) ? (+1.f) : (-1.f));
	}
	inline Velocity randomVelocity(float vmin, float vmax)
	{
		float speed = World::normalDist(World::randEngine)*(vmax-vmin) + vmin;
		float angle = randomAngleRad();
		return Velocity{speed*cosf(angle), speed*sinf(angle)};
	}
	inline float randomColor()
	{
		return World::colorDist(World::randEngine);
	}
	inline bool headsOrTails()
	{
		return World::headsOrTailsDist(World::randEngine);
	}
	inline bool isAnimated()
	{
		return World::animatedChoiceDist(World::randEngine);
	}
}

#endif  //  WORLD_H
