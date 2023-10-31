
#include <cmath>
#include "glPlatform.h"
#include "World.h"

using namespace earshooter;

Velocity Velocity::NULL_VELOCITY{0.f, 0.f};
int World::numLowerHedges;
float World::topScoreAreaHeight, World::waterHeight, World::waterY, World::topHedgeHeight;
float World::topHedgeY, World::lowerHedgeHeight, World::lowerHedgeWidth, World::offsetLowerHedge;
float World::lowerHedgeX, World::lowerHedgeY, World::middleHedgeHeight, World::middleHedgeY;
float World::roadHeight, World::bottomScoreArea;
float World::froggerStartHeight;
float World::bottomTopHedgeHeight;

void World::setScalingRatios(int& paneWidth, int& paneHeight){
	float widthRatio = WIDTH / paneWidth;
	float heightRatio = HEIGHT / paneHeight;
	float maxRatio = fmax(widthRatio,heightRatio);
//	Removed because this doesn’t work happily with interactive window resizing,
//	// If the two ratios differ by more than 5%,  then reject the dimensions
//	if (fabsf(widthRatio-heightRatio)/maxRatio > 0.05){
//		exit(15);
//	}

	pixelToWorldRatio = maxRatio;
	worldToPixelRatio = 1.f / pixelToWorldRatio;
	drawInPixelScale = pixelToWorldRatio;
	
	paneWidth = static_cast<int>(round(WIDTH * worldToPixelRatio));
	paneHeight = static_cast<int>(round(HEIGHT * worldToPixelRatio));

	topScoreAreaHeight = (HEIGHT * .05);
    numLowerHedges = 4;
    waterHeight = (HEIGHT * .5);
    waterY = (Y_MAX-topScoreAreaHeight-(waterHeight/2));
    topHedgeHeight = (HEIGHT/20);
    topHedgeY = (Y_MAX-topScoreAreaHeight-(topHedgeHeight/2));
    lowerHedgeHeight = HEIGHT /  10;
    lowerHedgeWidth = WIDTH /  8;
    offsetLowerHedge = WIDTH / 5;
    lowerHedgeX = X_MIN;
    lowerHedgeY = (Y_MAX-topScoreAreaHeight-(topHedgeHeight + lowerHedgeHeight/2));
    middleHedgeHeight = HEIGHT /  40;
    middleHedgeY = (Y_MAX-topScoreAreaHeight - waterHeight);
    roadHeight = (HEIGHT * .35);
    bottomScoreArea = (HEIGHT * .1);
	froggerStartHeight = (Y_MAX-topScoreAreaHeight - waterHeight - roadHeight);
	bottomTopHedgeHeight = roadHeight+waterHeight-topScoreAreaHeight-topHedgeHeight-lowerHedgeHeight+middleHedgeHeight;
}

WorldPoint earshooter::pixelToWorld(float ix, float iy)
{
	return WorldPoint{	World::X_MIN + ix*World::pixelToWorldRatio,
					World::Y_MAX - iy*World::pixelToWorldRatio
				};
}

WorldPoint earshooter::pixelToWorld(const PixelPoint& pt)
{
	return WorldPoint{	World::X_MIN + pt.x*World::pixelToWorldRatio,
					World::Y_MAX - pt.y*World::pixelToWorldRatio
				};
}

PixelPoint earshooter::worldToPixel(float wx, float wy)
{
	return PixelPoint{(wx - World::X_MIN)*World::worldToPixelRatio,
				 (World::Y_MAX - wy)*World::worldToPixelRatio};

}

PixelPoint earshooter::worldToPixel(const WorldPoint& pt)
{
	return PixelPoint{(pt.x - World::X_MIN)*World::worldToPixelRatio,
				 (World::Y_MAX - pt.y)*World::worldToPixelRatio};

}

void drawReferenceFrame()
{
	glBegin(GL_LINES);
		// X axis is red
		glColor3f(1.f, 0.f, 0.f);
		glVertex2f(0.f, 0.f);
		glVertex2f(World::WIDTH/25.f, 0.f);
		// Y axis is green
		glColor3f(0.f, 1.f, 0.f);
		glVertex2f(0.f, 0.f);
		glVertex2f(0.f, World::WIDTH/25.f);
	glEnd();
}