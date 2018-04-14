/* Author: Michael Trinh
** Partner: Thana Sithisombath
** CS256-01, Winter 2018
** Lab Assignment #2 Part #1
** Description:
**     Swap Values of 2 int values and display them
*/

#include "swap.h"
#include <iostream>

void get_numbers (int& input1, int& input2) {
    using namespace std;
    cout << "Enter two integers: ";
    cin >> input1 >> input2;
}

void swap_values (int& variable1, int& variable2) {
    int temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

void show_results (int output1, int output2) {
    using namespace std;
    cout << "In reverse order the numbers are: "
         << output1 << " " << output2 << endl;
}
