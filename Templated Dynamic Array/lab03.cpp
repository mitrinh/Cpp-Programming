/* Author: Michael Trinh
** Partner: Vinh Duc Le
** CS256-01, Winter 2018
** Lab Assignment #3
** Description:
**     Output 3 different types of arrays using a dynamically 
**     allocated array using a funcion template
*/

#include "Array.h"
#include <fstream>
#include <iostream>
using namespace std;

#define MAX 100

/*
** populate the array from the input data file and return
** the number of element count
*/
template <class T>
int read (string filename, Array<T>& data) {
    // open file
    ifstream inputFile;
    inputFile.open(filename.c_str());
    if (inputFile.fail()) {
        cout << "Unable to read file: " << filename << endl;
        return -1;
    }
    int length = 0;
    T temp;
    // read each piece of data using a while loop
    while ((length < MAX) && (inputFile >> temp)) {        
	data.set(length,temp);
	length++;
    }
    // close file
    inputFile.close();
    return length;
}

/*
** compute the sum of the array
*/
template <class T>
T sum (Array<T>& data, int count) {
    T result;
    // loop through each element in the array and add it to result
    for (int i = 0; i < count; i++)
        result += data.get(i);
    return result;
}

/*
** outputs the elements in the array
*/

template <class T>
void dump (Array<T>& data, int count) {
    // loop through the array and output each element
    for (int i = 0; i < count; i++)
        cout << data.get(i) << endl;
}

int main (int argc, char* argv[]) {

    cout << "INTEGER ARRAY" << endl;
    Array<int> iarray(MAX);
    int count = read ("/user/thuang/cs256/integers.dat", iarray);
    dump (iarray, count);
    if (count >= 0)
        cout << "sum = " << sum(iarray, count) << endl;
    cout << endl;
    cout << "FLOAT ARRAY" << endl;
    Array<float> farray(MAX);
    count = read ("/user/thuang/cs256/floats.dat", farray);
    dump (farray, count);
    if (count >= 0)
        cout << "sum = " << sum(farray, count) << endl;
    cout << endl;
    cout << "STRING ARRAY" <<endl;
    Array<string> sarray(MAX);
    count = read ("/user/thuang/cs256/names.dat", sarray);
    dump (sarray, count);
    if (count >= 0)
        cout << "sum = " << sum(sarray, count) << endl;
    return 0;
}


