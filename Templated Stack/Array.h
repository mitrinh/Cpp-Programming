/* Author: Michael Trinh
** Partner: No available partners
** CS256-01, Winter 2018
** Lab Assignment #4
** Description:
**     Output 3 different types of Stacks using a dynamically
**     allocated Stack via using a function template
*/

#include <cstddef>

#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {

    public:
        Array(int size);
	
	/* cleanup the dynamically allocated array */
	~Array();

        /* set value in the array */
	void set(int index, T& value);

	/* get value in the array */
	T& get(int index);

    private:
        T* array_; /* dynamic allocated array of the same type */
};
    template <class T>
    Array<T>::Array(int size){
        array_ = new T[size];
    }
    template <class T>
    Array<T>::~Array(){
        delete[] array_;
	array_ = NULL;
    }
    
    template <class T>
    void Array<T>::set(int index, T& value){
        array_[index] = value;
    }

    template <class T>
    T& Array<T>::get(int index) {
        return array_[index];
    }
#endif

