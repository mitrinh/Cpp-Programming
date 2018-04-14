/* Author: Michael Trinh
** Partner: Thana Sithisombath
** CS256-01, Winter 2018
** Lab Assignment #2 Part #2
** Description:
**     Reads an input file that contains many right triangle dimensions data
**         and compute the hypotenuse of each
*/

#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

class RightTriangle {
    public:
        RightTriangle(float a, float b);
        float getHypotenuse(); /* computes the hypotenuse */
    private:
        float a;
        float b;
};

#endif /* RIGHT_TRIANGLE_H */
