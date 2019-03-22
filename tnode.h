#ifndef _TNODE
#define _TNODE
#include<iostream>
using namespace std;

template<class type> class tnode {
        private:
                int height; //for duplicates
                type data;
                tnode<type>* leftPtr;
                tnode<type>* rightPtr;
         public: 
                tnode();
                tnode(type item);
                tnode(type item,tnode<type>* left, tnode<type>* right);
                tnode<type>* getLeft();
                tnode<type>* getRight();
                type getItem();
                void setRight(tnode<type>* right);
                void setLeft(tnode<type>* left);
                void setHeight(int value);
                int getHeight();
};
//constructors begin
template<class type>
tnode<type>::tnode(){
    height = 0;
    leftPtr = NULL;
    rightPtr = NULL;
}
template<class type>
tnode<type>::tnode(type item){
    data = item;
}

template<class type>
tnode<type>::tnode(type item,tnode<type>* left, tnode<type>* right){
    data = item;
    leftPtr = left;
    rightPtr = right;
}
//constructors end
//setters && getters begin
template<class type>
tnode<type>* tnode<type>::getLeft(){
    return leftPtr;
}

template<class type>
tnode<type>* tnode<type>::getRight(){
    return rightPtr;
}

template<class type>
void tnode<type>::setLeft(tnode<type>* left){
    leftPtr = left;
}

template <class type>
void tnode<type>::setRight(tnode<type>* right){
    rightPtr = right;
}
template <class type>
type tnode<type>::getItem(){
    return data;
}
template<class type>
void tnode<type>::setHeight(int value){
    height = value;
}
template <class type>
int tnode<type>::getHeight(){
    return height;
}
//setters && getters end



#endif
