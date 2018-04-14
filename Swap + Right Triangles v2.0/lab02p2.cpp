/* Author: Michael Trinh
** Partner: Thana Sithisombath
** CS256-01, Winter 2018
** Lab Assignment #2 Part #2
** Description:
**     Reads an input file that contains many right triangle dimensions data
**         and compute the hypotenuse of each
*/

#include "RightTriangle.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    // print usage if wrong # of args
    if (argc != 2) {
        cout << "./lab02p2 <triangle file name>" << endl;
        return 0;
    }

    // open file via input stream
    ifstream input;
    input.open (argv[1]);
    if (input.fail()) { // check if readable
        cout << "Unable to read file: " << argv[1] << endl;
        return -1;
    }

    // set the dimensions to a local variable
        float a = 0.0;
        float b = 0.0;

    // loop each set of dimensions
    while (input >> a >> b) {
        // make and replace triangle each iteration
        RightTriangle triangle(a,b);        
        // print each dimension of Right Triangle
        cout << "Right triangle: a=" << a
             << " b=" << b
             << " c = " << triangle.getHypotenuse() << endl; // call getHypotenuse() function
    } // end while 
    input.close();
    return 0;
}
