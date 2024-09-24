#include "node.h";

node::~node()
{
    delete this->link;
}
node::node()
{
    this->link = NULL;
}
node::node(Student s , node* l)
{
    this->student = s;
    this->link = l;
}
Student node::getStudent(){
    return this->student;
}
node* node::getLink(){
    return this->link;

}
void node::setLink(node* l){
    this->link = l;
}
void node::setStudent(Student s ){
    this->student = s;
}
