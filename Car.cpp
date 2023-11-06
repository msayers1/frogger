// Car.cpp
#include <iostream>
#include <vector>
#include "Car.h"
#include "ComplexGraphicObject.h"
#include "AnimatedObject.h"

using namespace earshooter;

float CarNumberFloat, carSpeed, carPosition;
float carSizeX = 2;
float carSizeY = 1;


struct Color {
    // red
    float r;
    // green
    float g;
    // blue
    float b;
};

Color CarRed = {1.0f, .0f, .0f};



Car::Car(CarNumber number, CarSpeed speed, float x, float y)
    :Object(x, y, 0),
    ComplexGraphicObject(x, y, 0),
    AnimatedObject(x, y, 0, 0, 0, 0)
{
    // switch(number){
    //     case ONE:
    //         CarNumberFloat = 1;
    //         carPosition = 0;  
    //         break;
    //     case TWO:
    //         CarNumberFloat = 2;  
    //         carPosition = -1 * carSize;
    //         break;
    //     case THREE:
    //         CarNumberFloat = 3;
    //         carPosition = -1.5 * carSize;
    //         break;
    // }
    
    switch(speed){
        case CAR_BACK_FAST:
            carSpeed = -3;  
            break;
        case CAR_BACK_MODERATE:
            carSpeed = -2;  
            break;
        case CAR_BACK_SLOW:
            carSpeed = -1;  
            break;
        case CAR_SLOW:
            carSpeed = 1;  
            break;
        case CAR_MODERATE:
            carSpeed = 2;  
            break;
        case CAR_FAST:
            carSpeed = 3;  
            break;
    }
    
    setSpeedX(carSpeed);
    //Rectangle(float centerX, float centerY, float angle, float width, float height, float r, float g, float b);
    // addPart(std::make_shared<Ellipse>((x-(CarNumberFloat/2)),y,0, .5,.5,CarRed.r, CarRed.g, CarRed.b ));
    // addPart(std::make_shared<Ellipse>(x,y,0, CarNumberFloat,1,CarRed.r, CarRed.g, CarRed.b ));
    // addPart(std::make_shared<Ellipse>((x + (CarNumberFloat/2)),y,0, .5,.5,EndWhite.r, EndWhite.g, EndWhite.b ));
    switch(number){
        case CAR_ONE:
            addPart(std::make_shared<Ellipse>(x,y,0, carSizeX,carSizeY,CarRed.r, CarRed.g, CarRed.b ));
            break;
        case CAR_TWO:
            addPart(std::make_shared<Ellipse>(((-(1.5 * carSizeX))+x),y,0,carSizeX,carSizeY,CarRed.r, CarRed.g, CarRed.b ));
            addPart(std::make_shared<Ellipse>(((1.5 * carSizeX)+x),y,0, carSizeX,carSizeY, CarRed.r, CarRed.g, CarRed.b ));
            
            break;
        case CAR_THREE:
            addPart(std::make_shared<Ellipse>((-(2.5 * carSizeX)+x),y,0,carSizeX,carSizeY,CarRed.r, CarRed.g, CarRed.b ));
            addPart(std::make_shared<Ellipse>(x,y,0, carSizeX,carSizeY, CarRed.r, CarRed.g, CarRed.b ));
            addPart(std::make_shared<Ellipse>(((2.5 * carSizeX)+x),y,0,carSizeX,carSizeY,CarRed.r, CarRed.g, CarRed.b ));
            break;
    }

	// for(int i = 0; i < 3; i++){
	// 	// addPart(std::make_shared<Ellipse>(x,y,0, CarNumberFloat,1,CarRed.r, CarRed.g, CarRed.b ));
	// 	carPosition = carPosition + 12;
	// }
    
}
    