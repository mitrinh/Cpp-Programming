/* Author: Michael Trinh
** Partner: No available partners
** CS256-01, Winter 2018
** Lab Assignment #4
** Description:
**     Output 3 different types of Stacks using a dynamically 
**     allocated Stack via using a function template
*/

#include "Stack.h"
#include <fstream>
#include <iostream>
using namespace std;

#define MAX 100

/*
** populate the array from the input data file and return
** the number of element count
*/
template <class T>
int read (string filename, Stack<T>& data) {
    // open file
    ifstream inputFile;
    inputFile.open(filename.c_str());
    if (inputFile.fail()) {
        cout << "Unable to read file: " << filename << endl;
        return -1;
    }
    int length = 0;
    T temp = T();
    // read each piece of data using a while loop
    while ((length < MAX) && (inputFile >> temp)) {        
	data.push(temp);
	length++;
    }
    // close file
    inputFile.close();
    return length;
}

/*
** compute the sum of the Stack
*/
 template <class T>
T sum (Stack<T>& data, int count) {
    T result = T();
    T* tempArray = new T[count];
    // pop each element out of the Stack and add it to result
    for (int i=0; i < count; i++) {
        // put each element at back of array first so the Stack is in the right order
        tempArray[count - i - 1] = data.pop();
	// add each element to the result
        result += tempArray[count - i -1];
    }
    // push back all the elements back to Stack since we don't want to change Stack
    for (int i=0; i < count; i++)
        data.push(tempArray[i]);
    delete[] tempArray;
    tempArray = NULL;
    return result;
} 

/*
** outputs the elements in the array
*/

template <class T>
void dump (Stack<T>& data, int count) {
    T* tempArray = new T[count]; 
    // loop through and pop each element in the stack and output it
    for (int i=0; i < count; i++) {
	// put each element at back of array first so the Stack is in the right order
	tempArray[count - i - 1] = data.pop();
        cout << tempArray[count - i - 1] << endl;
    }
    // push back all the elements back to Stack since we don't want to change Stack
    for (int i=0; i < count; i++)
        data.push(tempArray[i]);
    delete[] tempArray;
    tempArray = NULL;
}

int main (int argc, char* argv[]) {

    cout << "INTEGER ARRAY" << endl;
    Stack<int> istack(MAX);
    int count = read ("/user/thuang/cs256/integers.dat", istack);
    dump (istack, count);
    if (count >= 0)
        cout << "sum = " << sum(istack, count) << endl;
    cout << endl;
    cout << "FLOAT ARRAY" << endl;
    Stack<float> fstack(MAX);
    count = read ("/user/thuang/cs256/floats.dat", fstack);
    dump (fstack, count);
    if (count >= 0)
        cout << "sum = " << sum(fstack, count) << endl;
    cout << endl;
    cout << "STRING ARRAY" <<endl;
    Stack<string> sstack(MAX);
    count = read ("/user/thuang/cs256/names.dat", sstack);
    dump (sstack, count);
    if (count >= 0)
        cout << "sum = " << sum(sstack, count) << endl;
    cout << endl;
    return 0;
}


