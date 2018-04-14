/* Author: Michael Trinh
** Partner: Thana Sithisombath
** CS256-01, Winter 2018
** Lab Assignment #2 Part #1
** Description:
**     Swap Values of 2 int values and display them
*/

#include "swap.h"

int main () {
    int first_num, second_num;

    get_numbers (first_num, second_num);
    swap_values (first_num, second_num);
    show_results (first_num, second_num);
    return 0;
}
