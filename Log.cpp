// Log.cpp
#include <iostream>
#include <vector>
#include "Log.h"
#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"

using namespace earshooter;

float logSizeFloat, logSpeed;

struct Color {
    // red
    float r;
    // green
    float g;
    // blue
    float b;
};

Color LogBrown = {.545098f, .270588f, .07451f};
Color EndWhite = {1.0f, 1.0f, 1.0f};
std::vector<std::pair<float,float>> leftBaseWing = {{0.0f,1.6f}, {-.3f,1.6f} ,{-1.f,-2.0f},{0.0f,-0.5f}};
std::vector<std::pair<float,float>> rightBaseWing = {{0.3f,1.6f}, {0.0f,1.6f},{0.f,-0.5f},{1.0f,-2.0f}};
std::vector<std::pair<float,float>> leftFrontWing = {{0.0f,2.0f},{0.f,1.5f},{-0.9f,1.2f}};
std::vector<std::pair<float,float>> rightFrontWing = {{0.0f,2.0f},{0.f,1.5f},{0.9f,1.2f}};


Log::Log(LogSize size, LogSpeed speed, float x, float y)
    :ComplexGraphicObject(0, 0, 0),
    AnimatedObject(0, 0, 0, 0, 0, 0),
    Object(0,0,0)
{
    switch(size){
        case SMALL:
            logSizeFloat = 4;  
            break;
        case MEDIUM:
            logSizeFloat = 6;  
            break;
        case LARGE:
            logSizeFloat = 8;  
            break;
    }
    
    switch(speed){
        case BACK_FAST:
            logSpeed = -3;  
            break;
        case BACK_MODERATE:
            logSpeed = -2;  
            break;
        case BACK_SLOW:
            logSpeed = -1;  
            break;
        case SLOW:
            logSpeed = 1;  
            break;
        case MODERATE:
            logSpeed = 2;  
            break;
        case FAST:
            logSpeed = 3;  
            break;
    }
    
    setSpeedX(logSpeed);
    //Rectangle(float centerX, float centerY, float angle, float width, float height, float r, float g, float b);
    addPart(std::make_shared<Ellipse>((x-(logSizeFloat/2)),y,0, .5,.5,LogBrown.r, LogBrown.g, LogBrown.b ));
    addPart(std::make_shared<Rectangle>(x,y,0, logSizeFloat,1,LogBrown.r, LogBrown.g, LogBrown.b ));
    addPart(std::make_shared<Ellipse>((x + (logSizeFloat/2)),y,0, .5,.5,EndWhite.r, EndWhite.g, EndWhite.b ));
    
    
}
    