// StaticBackground.cpp
#include <iostream>
#include <vector>
#include "StaticBackground.h"
#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"
#include "World.h"

using namespace earshooter;

struct Color {
    // red
    float r;
    // green
    float g;
    // blue
    float b;
};

Color GreenGrass = {.193725f, .285882f, .06f};
Color PurpleRoadEdge = { .172157f, .12f, .238431f};
Color BlueWater = {.0f, .0f, 1.0f};
// Color thruster = {.41f, .435f, .70f};
// Color cockpit = {.6f, .87f, .87f};
// std::vector<std::pair<float,float>> GreenGrassCoords = {{0.0f,1.6f}, {-.3f,1.6f} ,{-1.f,-2.0f},{0.0f,-0.5f}};
// std::vector<std::pair<float,float>> rightBaseWing = {{0.3f,1.6f}, {0.0f,1.6f},{0.f,-0.5f},{1.0f,-2.0f}};
// std::vector<std::pair<float,float>> leftFrontWing = {{0.0f,2.0f},{0.f,1.5f},{-0.9f,1.2f}};
// std::vector<std::pair<float,float>> rightFrontWing = {{0.0f,2.0f},{0.f,1.5f},{0.9f,1.2f}};

StaticBackground::StaticBackground()
    :Object(0.f,0.f,0.f),
    ComplexGraphicObject(0.f, 0.f, 0.f),
    AnimatedObject(0.f,0.f, 0.f, 0.f,0.f, 0.f)
{

    if((World::topScoreAreaHeight + World::waterHeight + World::roadHeight + World::bottomScoreArea) != World::HEIGHT){
        std::cerr << "Error: Problem with Percentages." << std::endl;
    }
    //(World::Y_MAX-(World::HEIGHT * .05) - (World::HEIGHT * .5) - (World::HEIGHT * .35))
    float localLowerHedgeX = World::lowerHedgeX;
    //Rectangle(float centerX, float centerY, float angle, float width, float height, float r, float g, float b);
   addPart(std::make_shared<Rectangle>(0,World::waterY,0, (World::WIDTH),World::waterHeight,BlueWater.r, BlueWater.g, BlueWater.b ));
   addPart(std::make_shared<Rectangle>(0,World::topHedgeY,0, (World::WIDTH),World::topHedgeHeight,GreenGrass.r, GreenGrass.g, GreenGrass.b ));
   //Hedges in Lower full not the end and beginning. 
    for (int i = 0; i < 6;i++) {
        addPart(std::make_shared<Rectangle>(localLowerHedgeX,World::lowerHedgeY,0, World::lowerHedgeWidth,World::lowerHedgeHeight,GreenGrass.r, GreenGrass.g, GreenGrass.b ));
        localLowerHedgeX = localLowerHedgeX + World::offsetLowerHedge;
        // std::cout << localLowerHedgeX << "|" << World::offsetLowerHedge << std::endl;
    }
   addPart(std::make_shared<Rectangle>(0, World::middleHedgeY,0, (World::WIDTH),World::middleHedgeHeight,PurpleRoadEdge.r, PurpleRoadEdge.g, PurpleRoadEdge.b ));
   float lowerHedgeY = World::middleHedgeY - World::roadHeight;
   addPart(std::make_shared<Rectangle>(0, lowerHedgeY,0, (World::WIDTH),World::middleHedgeHeight,PurpleRoadEdge.r, PurpleRoadEdge.g, PurpleRoadEdge.b ));
    
}
    