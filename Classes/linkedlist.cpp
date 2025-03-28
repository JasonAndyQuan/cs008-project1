#include "linkedlist.h"
#include "student.h"
#include <iostream>
template <class dataType>
linkedList<dataType>::linkedList()
{
    this->head = nullptr;
}
template <class dataType>
linkedList<dataType>::linkedList(node<dataType> *newHead)
{
    this->head = newHead;
}

template <class dataType>
node<dataType>* linkedList<dataType>::getHead(){
    return this->head;
}


template<class dataType>
void linkedList<dataType>::deleteAll(){
    if (!this->head)
        return;
    node<dataType>* temp = this->head;
    while (this->head){
        this->head = this->head->getLink();
        delete temp;
        temp = this->head;  
    }
    head = nullptr;
}
// template <class dataType>
// linkedList<dataType>::~linkedList()
// {
//     std:: cout << " 1 ";
//     node<dataType> *temp = this->head;
//     while (temp)
//     {
//         node<dataType> *lag = temp;
//         temp = temp->getLink();
//         delete lag;
//     }
//     head = nullptr;
// }
template <class dataType>
void linkedList<dataType>::printList()
{
    // precondition: takes in a linkedlist
    // postcondition : prints out linked list
    if (!this->head)
    {
        std::cout << "List is Empty\n";
        return;
    }
    node<dataType> *temp = this->head;
    while (temp)
    {
        std::cout << temp->getData() << "->";
        temp = temp->getLink();
    }
    std::cout << "NULL\n";
}

template <typename dataType>
void linkedList<dataType>::insertHead(dataType data)
{
    // precondition: takes in a linkedlist and a data
    // postcondition: Inserts a new node with data into the list

    node<dataType> *newNode = new node<dataType>;
    newNode->setData(data);
    newNode->setLink(this->head);
    this->head = newNode;
}

template <class dataType>
void linkedList<dataType>::printStudents(){
    // precondition: takes in a linkedlist
    // postcondition : Prints out the students data (uses .getName() member function).
    node<dataType>* temp = this->head;
    while (temp){
        std::cout << temp->getData().getId() <<  " " << temp->getData().getName() << std::endl;
        temp = temp->getLink();
    }
}

template <class dataType>
void linkedList<dataType>::insert(dataType data)
{   
    // precondition: takes in a linkedlist and a data
    // postcondition : Inserts a new node with data into the list, in a sorted manner.

    if (!this->head)
    {
        this->insertHead(data);
        return;
    }

    node<dataType> *temp = this->head;
    while (temp->getLink())
        temp = temp->getLink();

    node<dataType> *newNode = new node<dataType>;
    newNode->setData(data);

    newNode->setLink(temp->getLink());
    temp->setLink(newNode);
}

template <typename dataType>
void linkedList<dataType>::deleteHead()
{
    // precondition: takes in a linkedlist
    // postcondition : deletes the head of a linked list;

    if (!this->head)
    {
        std::cout << "List is already empty" << std::endl;
        return;
    }

    node<dataType> *temp = this->head;
    this->head = this->head->getLink();
    delete temp;
}

template <typename dataType>
bool linkedList<dataType>::deleteSpecific(dataType value)
{
    // precondition: takes in a linked list and a value
    // postcondition: deletes the node with the given data value, returns true if successful, false if not found
    node<dataType> *finder = this->head;
    if (!finder)
    {
        std::cout << "List is empty\n";
        return false;
    }
    if (finder->getData() == value)
    {
        this->deleteHead();
        return true;
    }

    while (finder->getLink() && !(finder->getLink()->getData() == value))
        finder = finder->getLink();

    if (!finder->getLink())
    {
        return false;
    }

    node<dataType> *temp = finder->getLink();
    finder->setLink(temp->getLink());
    delete temp;
    return true;
}
