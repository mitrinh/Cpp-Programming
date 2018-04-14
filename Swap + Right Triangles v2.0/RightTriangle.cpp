/* Author: Michael Trinh
** Partner: Thana Sithisombath
** CS256-01, Winter 2018
** Lab Assignment #2 Part #2
** Description:
**     Reads an input file that contains many right triangle dimensions data
**         and compute the hypotenuse of each
*/

#include "RightTriangle.h"
#include <cmath>

    RightTriangle::RightTriangle(float x, float y) {            
        a = x;
        b = y;         
    }

    float RightTriangle::getHypotenuse() {
        // square a and b
        float newA = a * a;
        float newB = b * b;
        // take square root of sum for hypotenuse
        float hypotenuse = sqrt(newA + newB);
        return hypotenuse;
    }
