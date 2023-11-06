// Truck.cpp
#include <iostream>
#include <vector>
#include "Truck.h"
#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"

using namespace earshooter;

float truckSizeFloat, truckSpeed;

struct Color {
    // red
    float r;
    // green
    float g;
    // blue
    float b;
};

Color TruckBrown = {.2118f, .12555f, .0510f};



Truck::Truck(TruckSize size, TruckSpeed speed, float x, float y)
    :ComplexGraphicObject(x, y, 0),
    AnimatedObject(x, y, 0, 0, 0, 0),
    Object(x,y,0)
{
    switch(size){
        case TRUCK_SMALL:
            truckSizeFloat = 4;  
            break;
        case TRUCK_MEDIUM:
            truckSizeFloat = 6;  
            break;
        case TRUCK_LARGE:
            truckSizeFloat = 8;  
            break;
    }
    
    switch(speed){
        case TRUCK_BACK_FAST:
            truckSpeed = -3;  
            break;
        case TRUCK_BACK_MODERATE:
            truckSpeed = -2;  
            break;
        case TRUCK_BACK_SLOW:
            truckSpeed = -1;  
            break;
        case TRUCK_SLOW:
            truckSpeed = 1;  
            break;
        case TRUCK_MODERATE:
            truckSpeed = 2;  
            break;
        case TRUCK_FAST:
            truckSpeed = 3;  
            break;
    }
    
    setSpeedX(truckSpeed);
    //Rectangle(float centerX, float centerY, float angle, float width, float height, float r, float g, float b);
    addPart(std::make_shared<Rectangle>(x,y,0, truckSizeFloat,1,TruckBrown.r, TruckBrown.g, TruckBrown.b ));
    
    
}
    