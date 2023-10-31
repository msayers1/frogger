// Turtle.cpp
#include <iostream>
#include <vector>
#include "Turtle.h"
#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"

using namespace earshooter;

float TurtleNumberFloat, turtleSpeed, turtlePosition;
float turtleSizeX = 2;
float turtleSizeY = 1;


struct Color {
    // red
    float r;
    // green
    float g;
    // blue
    float b;
};

Color TurtleGreen = {.545098f, .270588f, .07451f};
Color TurtleOtherColorToSignifySumberging = {1.0f, 1.0f, 1.0f};


Turtle::Turtle(TurtleNumber number, TurtleSpeed speed, float x, float y)
    :Object(0, 0, 0),
    ComplexGraphicObject(0, 0, 0),
    AnimatedObject(0, 0, 0, 0, 0, 0)
{
    // switch(number){
    //     case ONE:
    //         TurtleNumberFloat = 1;
    //         turtlePosition = 0;  
    //         break;
    //     case TWO:
    //         TurtleNumberFloat = 2;  
    //         turtlePosition = -1 * turtleSize;
    //         break;
    //     case THREE:
    //         TurtleNumberFloat = 3;
    //         turtlePosition = -1.5 * turtleSize;
    //         break;
    // }
    
    switch(speed){
        case TURTLE_BACK_FAST:
            turtleSpeed = -3;  
            break;
        case TURTLE_BACK_MODERATE:
            turtleSpeed = -2;  
            break;
        case TURTLE_BACK_SLOW:
            turtleSpeed = -1;  
            break;
        case TURTLE_SLOW:
            turtleSpeed = 1;  
            break;
        case TURTLE_MODERATE:
            turtleSpeed = 2;  
            break;
        case TURTLE_FAST:
            turtleSpeed = 3;  
            break;
    }
    
    setSpeedX(turtleSpeed);
    //Rectangle(float centerX, float centerY, float angle, float width, float height, float r, float g, float b);
    // addPart(std::make_shared<Ellipse>((x-(TurtleNumberFloat/2)),y,0, .5,.5,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
    // addPart(std::make_shared<Ellipse>(x,y,0, TurtleNumberFloat,1,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
    // addPart(std::make_shared<Ellipse>((x + (TurtleNumberFloat/2)),y,0, .5,.5,EndWhite.r, EndWhite.g, EndWhite.b ));
    switch(number){
        case ONE:
            addPart(std::make_shared<Ellipse>(x,y,0, turtleSizeX,turtleSizeY,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
            break;
        case TWO:
            addPart(std::make_shared<Ellipse>(((-(1.5 * turtleSizeX))+x),y,0,turtleSizeX,turtleSizeY,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
            addPart(std::make_shared<Ellipse>(((1.5 * turtleSizeX)+x),y,0, turtleSizeX,turtleSizeY, TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
            
            break;
        case THREE:
            addPart(std::make_shared<Ellipse>((-(2.5 * turtleSizeX)+x),y,0,turtleSizeX,turtleSizeY,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
            addPart(std::make_shared<Ellipse>(x,y,0, turtleSizeX,turtleSizeY, TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
            addPart(std::make_shared<Ellipse>(((2.5 * turtleSizeX)+x),y,0,turtleSizeX,turtleSizeY,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
            break;
    }

	// for(int i = 0; i < 3; i++){
	// 	// addPart(std::make_shared<Ellipse>(x,y,0, TurtleNumberFloat,1,TurtleGreen.r, TurtleGreen.g, TurtleGreen.b ));
	// 	turtlePosition = turtlePosition + 12;
	// }
    
}
    