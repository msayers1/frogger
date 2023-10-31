//
//   Polygon.hpp
//   Prog01Version1
//   
//  Hope for being able to do different polygons. 
//
//   Created by Michael Sayers on 9/22/2023 
//   Modified from Class Code Examples from CS406 Jean-Yves Hervé
//

#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <utility>
#include <stdio.h>
#include "GraphicObject.h"
namespace earshooter
{
    class Polygon : public GraphicObject
    {
        private:
        
            // float _centerX, _centerY, _scaleX, _scaleY, _angle;
            float _scaleX, _scaleY;
            float _red, _green, _blue;
            std::vector<std::pair<float,float>> _vertexVector;
            // int _type;
            // float _thickness,_modification;
            

        public:
            Polygon(float centerX, float centerY, float angle, float scaleX, float scaleY,std::vector<std::pair<float,float>> vertexVector,float red, float green, float blue);
            //type will take the points and do stuff with them. 
            // Polygon(float centerX, float centerY, float angle, float scaleX, float scaleY,std::vector<std::pair<float,float>> vertexVector,float red, float green, float blue, int type,float thickness);
            
            ~Polygon();
            
            void draw() const;

            //disabled constructors & operators
            
            Polygon() = delete;
            Polygon(const Polygon& obj) = delete;	// copy
            Polygon(Polygon&& obj) = delete;		// move
            Polygon& operator = (const Polygon
            & obj) = delete;	// copy operator
            Polygon& operator = (Polygon&& obj) = delete;
    };
}


#endif // POLYGON_HPP