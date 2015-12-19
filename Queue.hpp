/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   11/19/2015                                   *
 ** Description: This is the class specification file    *
 *  of a class called Queue. This class Implement an     *
 *  abstract data type using linked structures.          *
 ********************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include "Queue.hpp"


//Class Declaration
class Queue
{
protected:
    // each node consists of an integer value and pointers
    // to the next and previous nodes
    struct QueueNode
    {
        int value;
        QueueNode *next;
        QueueNode *prev;
        QueueNode(int value1, QueueNode *next1 = NULL, QueueNode *prev1 = NULL)
        {
            value = value1;
            next = next1;
            prev = prev1;
        }
    };
    
    QueueNode *front;  // front node
    QueueNode *back;   // back node
    
public:
    
    Queue();                   // constructor, empty queue
    ~Queue();                  // destructor
    void addBack(int);         // puts on item at the end of the structure
    int getFront();            // returns the value at the front of the structure
    void removeFront();        // remove a node from the front
    void display() const;      // display the queue
    
};
#endif

