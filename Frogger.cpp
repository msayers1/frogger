// Frogger.cpp
#include <iostream>
#include <vector>
#include "Frogger.h"
#include "ComplexGraphicObject.h"
// #include "AnimatedObject.h"
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

Color FroggerColor = {.390588f, .362745f, .006275f};
// Color thruster = {.41f, .435f, .70f};
// Color cockpit = {.6f, .87f, .87f};
// std::vector<std::pair<float,float>> GreenGrassCoords = {{0.0f,1.6f}, {-.3f,1.6f} ,{-1.f,-2.0f},{0.0f,-0.5f}};
// std::vector<std::pair<float,float>> rightBaseWing = {{0.3f,1.6f}, {0.0f,1.6f},{0.f,-0.5f},{1.0f,-2.0f}};
// std::vector<std::pair<float,float>> leftFrontWing = {{0.0f,2.0f},{0.f,1.5f},{-0.9f,1.2f}};
// std::vector<std::pair<float,float>> rightFrontWing = {{0.0f,2.0f},{0.f,1.5f},{0.9f,1.2f}};


Frogger::Frogger()
    :ComplexGraphicObject(0.f, 0.f, 0.f),
    // AnimatedObject(0.f,0.f, 0.f, 0.f,0.f, 0.f),
    Object(0.f,0.f,0.f)
{
    // Rectangle(float centerX, float centerY, float angle, float width, float height,
				// float red, float green, float blue)
    addPart(std::make_shared<Rectangle>(0,World::froggerStartHeight,0, 1,1, FroggerColor.r, FroggerColor.g, FroggerColor.b ));
    
    
}
    