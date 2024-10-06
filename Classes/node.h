#pragma once

template<class dataType>
class node {
private:
    dataType data;
    node<dataType>* link;

public:   
    node();
    node(node<dataType>*, dataType); 

    dataType getData() const; 
    void setData(dataType); 

    node<dataType>* getLink() const; 
    void setLink(node<dataType>*); 
};


template<class dataType>
node<dataType>::node() {
    this->link = nullptr;
}

template<class dataType>
node<dataType>::node(node<dataType>* next, dataType data) {
    this->link = next; 
    this->data = data; 
}

template<class dataType>
dataType node<dataType>::getData() const {
    return this->data;
}

template<class dataType>
void node<dataType>::setData(dataType newData) {
    this->data = newData;
}

template<class dataType>
node<dataType>* node<dataType>::getLink() const {
    return this->link;
}

template<class dataType>
void node<dataType>::setLink(node<dataType>* link) {
    this->link = link;
}
