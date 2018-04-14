/* Author: Michael Trinh
** Partner: No available partners
** CS256-01, Winter 2018
** Lab Assignment #4
** Description:
**     Output 3 different types of Stacks using a dynamically
**     allocated Stack via using a function template
*/

// @file: Stack.h
#ifndef STACK_H
#define STACK_H

#include "Array.h"
#include <iostream>
using namespace std;

template <class T>
class Stack : public Array<T> {
public:
    Stack(int size);
    ~Stack();

    void push (T& value);
    T& pop();
private:
    int length;
};

template <class T>
Stack<T>::Stack(int size) : Array<T>(size){
    length = size;
}

template <class T>
Stack<T>::~Stack() {
    Array<T>::~Array();
}

template <class T>
void Stack<T>::push(T& value) {
    T* temp = new T();
    // shift all stack elements to the right to allocate space for new value
    for (int i=0; i < length; i++) {
        *temp = Array<T>::get(i);
        Array<T>::set(i,value);
	value = *temp;
	delete temp;
	temp = new T();
    }     
}

template <class T>
T& Stack<T>::pop() {
    T* temp = new T();
    // gets the 1st element to return
    *temp = Array<T>::get(0);
    // shift all elements in the Stack to the left
    for (int i=1; i < length; i++) {
        Array<T>::set(i-1,Array<T>::get(i));
    }
    return *temp;
}

#endif
