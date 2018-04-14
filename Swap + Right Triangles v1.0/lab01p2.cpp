/* Author: Michael Trinh
** Partner: Maxim Ruzmaykin
** CS256-01, Winter 2018
** Lab Assignment #1 Part #2
** Description:
**     Compute and print the area of triangles.
*/
#include <iostream>
using namespace std;

// Main function
int main (int argc, char* argv[]) {
    // variables.
    int triangles = 0;
    double base;
    double height;
    double area = 0;
    
    cout << "How many triangles? ";
    cin >> triangles;
    for (int i=0; i < triangles; i++) {
        cout << '\n'
             << "-- Iteration " << i << " ---" << endl;

        // get base
        cout << "Base: ";
        cin >> base;
        
        // get height
	cout << "Height: ";
        cin >> height;
        
        // check if base and height are legitimate
        if ((base <= 0) || (height <= 0)) {
            cout << "Invalid Base or Height." << endl; 
        }           
        // otherwise compute and print area 
        else {
            // compute area A=(b*h)/2
            area = ((base * height) / 2);
            
            cout << "The area of the triangle for Base="
                 << base << " and Height=" 
                 << height << " is " << area << '.' << endl;
        }
    }
}
