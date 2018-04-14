/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// @file Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Queue {
    // display queue iteratively
    template <class N>
    friend N iterateQueue(int counter, const Queue<N>& myQueue);
public:
    Queue();
    ~Queue();

    // method to add a value to the end of the queue
    bool enqueue(const T& value);
    // method to remove a value from the beginning of the queue
    bool dequeue(T& value);

    int getSize() const;

private:
    Node<T>* head_;
    Node<T>* tail_;
    int length_;
};

template <class T>
Queue<T>::Queue() {
    head_ = tail_ = NULL;
    length_ = 0;
}

template <class T>
Queue<T>::~Queue() {
    Node<T>* temp = this->head_;
        while (temp != NULL) {
            this->head_ = this->head_->getNext();
            delete temp;
        temp = this->head_;
    }
}

template <class N>
N iterateQueue(int counter, const Queue<N>& myQueue) {
    // point node to the head of the queue
    Node<N>* node = myQueue.head_;
    // node is pointed to the node at the specified node in the counter
    for (int i = 0; i<counter;i++){
        node = node->getNext();
    }
    // return that node's value
    return node->getValue();
}

// method to add a value to the end of the queue
template <class T>
bool Queue<T>::enqueue(const T& value){
    // create new node that holds the value we want to add to queue
    Node<T>* node = new Node<T>(value, NULL);
    // if queue is empty, set the top of queue as 1st node in queue;
    if (this->getSize() == 0)
        this->head_ = node;
    // if queue isn't empty, set current node of tail to be node and set tail to be the new tail
    else
        this->tail_->setNext(node);
    this->tail_ = node;
    // increment queue size by 1
    this->length_++;
    return true;
}

// method to remove a value from the beginning of the queue
template <class T>
bool Queue<T>::dequeue(T& value) {
    // return false if queue is empty
    if (this->length_ == 0)
        return false;
    // make a node that is set to top of queue
    Node<T>* node = this->head_;
    // set top of queue down by 1 for next
    this->head_ = head_->getNext();
    // return the value of that node
    value = node->getValue();
    // delete unused data
    delete node;
    // decrement queue size by 1
    this->length_--;
    return true;
}

template <class T>
int Queue<T>::getSize() const {
    return this->length_;
}

#endif /* QUEUE_H */