#include "linkedlist.h"
#include <iostream>
template <class dataType>
linkedList<dataType>::linkedList()
{
    this->head = NULL;
}

template <class dataType>
linkedList<dataType>::linkedList(node<dataType> *newHead)
{
    this->head = newHead;
}

template <class dataType>
linkedList<dataType>::~linkedList()
{
    node<dataType> *temp = this->head;
    while (temp)
    {
        node<dataType> *lag = temp;
        temp = temp->getLink();
        delete lag;
    }
}

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
        temp = temp->getNextLink();
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
void linkedList<dataType>::insert(dataType data)
{   
    // precondition: takes in a linkedlist and a data
    // postcondition : Inserts a new node with data into the list, in a sorted manner.

    if (!this->head || data <= this->head->getData())
    {
        this->insertHead(data);
        return;
    }

    node<dataType> *temp = this->head;
    while (temp->getLink() && temp->getLink()->getData() < data)
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
void linkedList<dataType>::deleteSpecific(dataType value)
{
    // precondition: takes in a linked list and a value
    // postcondition: deletes the node with the given data value

    node<dataType> *finder = this->head;
    if (!finder)
    {
        std::cout << "List is empty\n";
        return;
    }
    if (finder->getData() == value)
    {
        this->deleteHead();
        return;
    }

    while (finder->getLink() && finder->getLink()->getData() != value)
        finder = finder->getLink();

    if (!finder->getLink())
    {
        std::cout << "Value not found \n";
        return;
    }

    node<dataType> *temp = finder->getLink();
    finder->setLink(temp->getLink());
    delete temp;
}
