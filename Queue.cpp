/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   11/19/2015                                   *
 ** Description: This is the class implementation file   *
 *  of a class called Queue. This class Implement an     *
 *  abstract data type using linked structures           *
 ********************************************************/


#include <iostream>
#include "Queue.hpp"

using namespace std;

/******************************************
**             Constructor                *
******************************************/
Queue::Queue()
{
    front = NULL;
    back = NULL;
}

/*********************************************************************
 ** Function: ~Queue
 ** Description: Destructor frees allocated memory.
 ** Parameters: none.
 ** Pre-Conditions: The queue must exist.
 ** Post-Conditions: All nodes will be deleted.
 *********************************************************************/
Queue::~Queue()
{
    if (front == NULL && back == NULL) {
        removeFront();}
}

/*********************************************************************
 ** Function: addBack
 ** Description: Add a node to the back of the queue.
 ** Parameters: none.
 ** Pre-Conditions: The queue must exist.
 ** Post-Conditions: A node will be added to the back of the queue.
 *********************************************************************/
void Queue::addBack(int num)
{
    QueueNode *newnode = new QueueNode(num);
    newnode->next = newnode; // circular
    
    // no elements in the list
    if(front == NULL && back == NULL){
        //the front and the back are sentinels
        front = back = newnode;
        //The sentinel points to itself in either direction.
        newnode = newnode->next; // sentinel
        newnode = newnode->prev; // sentinel
        std::cout <<back->value<<" has been added to the empty queue."<<std::endl;}
    
    else{
        newnode->next = front;
        back->next = newnode;
        back = newnode;
        std::cout <<back->value<<" has been added to the queue."<<std::endl;
    }
}

/*********************************************************************
 ** Function: removeFront
 ** Description: Remove a node from the front of the queue.
 ** Parameters: none.
 ** Pre-Conditions: The queue must exist.
 ** Post-Conditions: If the queue is not empty, a node will be removed
 **   from the front of the queue.
 *********************************************************************/
void Queue::removeFront()
{
    QueueNode *deletedNode;
    
    // no elements in the list
    if (front == NULL && back == NULL) {
        std::cout << "The Queue is empty!!! (removeFront)" <<std::endl;}
    
    else {
        
        std::cout <<front->value<<" has been removed from the Queue."<<std::endl;
        deletedNode = front;
        front = front->next;
        delete deletedNode;
    }
}

/*********************************************************************
 ** Function: getFront
 ** Description: Remove a node from the front of the queue.
 ** Parameters: none.
 ** Pre-Conditions: The queue must exist.
 ** Post-Conditions: If the queue is not empty, a node will be removed
 **   from the front of the queue.
 *********************************************************************/
int Queue::getFront()
{
    int item = 0;
    
    // no elements in the list
    if (front == NULL && back == NULL) {
        std::cout << "The queue is empty!!! (getFront)" <<std::endl;}
    
    else {
        item = front->value;
        std::cout <<"The value at the front of the structure is: "<<item<<std::endl;
        if(item < 1) {item = -1;}
        }
    
    return item;
}

/*********************************************************************
 ** Function: display
 ** Description: Display the entire queue.
 ** Parameters: none.
 ** Pre-Conditions: The queue must exist.
 ** Post-Conditions: The values in the queue will be printed in a row
 **                  from front to back.
 *********************************************************************/
void Queue::display() const
{
    if (front == NULL && back == NULL) {
        // nothing to see here
        std::cout <<"The queue is empty!!! (display)" << std::endl;}
    
    else {
        std::cout <<"THESE ARE THE VALUES STORED IN THE QUEUE (front to back):" << std::endl;
        QueueNode *node = front;    // start at front.
        
        while (node != NULL) {
            std::cout << "VALUE = "<<node->value
            <<"   ADDRESS = "<< node
            <<"   next = " <<node->next<<std::endl;
            node = node->next;}
    }
}

