#pragma once
template<class dataType>
class node {
    private:
        dataType data;
        node<dataType>* link;
    public:

        node<dataType>();
        node<dataType>(node<dataType>*, dataType);
        // ~node<dataType>();

        dataType getData() const;
        void setData(dataType);

        node<dataType>* getLink() const{
            return this->link;
        }

        void setLink(node<dataType>*);

};
