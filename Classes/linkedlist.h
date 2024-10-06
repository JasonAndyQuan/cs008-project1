#pragma once

#include "node.h"

template <class dataType>
class linkedList
{
    private:
        node<dataType>* head;
    public:
        linkedList<dataType>();
        linkedList<dataType>(node<dataType>*);
        // ~linkedList();

        node<dataType>* getHead();
        void printStudents();
        void printList(); //done
        void insert(dataType); // done
        void insertHead(dataType); //done
        void deleteHead(); //done
        void deleteSpecific(dataType); //done


};
