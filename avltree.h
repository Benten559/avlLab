#ifndef _AVLTREE
#define _AVLTREE
#include <iostream>
#include "tnode.h"
using namespace std;

template <class type> class avltree{
    private:
            tnode<type>* root;
    public:
            avltree();
            void traverse(tnode<type>* root);
            void display();
            void display(tnode<type>* root);
            void insert(type item);//helper
            tnode<type>* insertion(tnode<type>* tree, type item);
            void inorder(tnode<type>* tree);
            tnode<type>* getBottom(tnode<type>* tree); //gets the bottom left of a node
            tnode<type>* delNode(tnode<type>*tree,type item);
            void deleteNode(type item);
            int heightUpdate(tnode<type>* tree);
            int max(int a, int b);

};

template<class type> 
avltree<type>::avltree(){
    root = NULL;
}
template<class type>
void avltree<type>::traverse(tnode<type>* root){ //inorder utility
    if (root == NULL) return;
    else {
        traverse(root->getLeft());
        cout << root->getItem()<< " "<< "\n the height of this node: " << root->getHeight() << endl;
        traverse(root->getRight());
    }
}
template<class type> 
void avltree<type>::display(){ //primary for cout
    if (root == NULL) return;
    else {
        traverse(root);
    }
}
template<class type>
void avltree<type>::insert(type item){ //primary insertion function
    root = insertion(root,item);
}
template<class type>
tnode<type>* avltree<type>::insertion(tnode<type>* tree, type item){ //utility function for inserting
    if (tree == NULL){  //tree empty so it becomes the root
      tnode<type>* temp = new tnode<type>(item,NULL,NULL);
      tree = temp;
    }
    else {
        if(tree->getItem() > item){
            tree->setLeft(insertion(tree->getLeft(),item));
        }
        else {
            tree->setRight(insertion(tree->getRight(),item));
        }
    }
    tree->setHeight(heightUpdate(tree));
    return tree;
}
template<class type>
tnode<type>* avltree<type>::getBottom(tnode<type>* tree){ //returns the smallest node, used to find placeholder for an entire left subtree
    tnode<type>* temp = tree;
    while (temp->getLeft() != NULL){
        temp = temp->getLeft();
    }
    return temp;
}
template <class type>
tnode<type>* avltree<type>::delNode(tnode<type>* tree, type item){
    if( tree == NULL) return NULL;  //EMPTY TREE
    else if (tree->getItem() == item){  //FOUND NODE TO BE DELETED
        if ((tree->getRight() == NULL) && (tree->getLeft() != NULL)){ //CASE 1  FOUND AND HAS A LEFT SUBTREE
            tnode<type>* temp = tree->getLeft();
            tree->setLeft(NULL);
            tree->setRight(NULL);
            delete tree;
            temp->setHeight(heightUpdate(temp));
            return temp;
        }
        else if ((tree->getLeft() == NULL) && (tree->getRight() != NULL)){//CASE 2: FOUND AND HAS A RIGHT SUBTREE
            tnode<type>* temp = tree->getRight();//this will be new root
            tree->setRight(NULL);
            tree->setLeft(NULL);
            delete tree;
            temp->setHeight(heightUpdate(temp));
            return temp;
        }
        else{                                   //CASE 3: FOUND THE NODE AND IT HAS A LEFT AND RIGHT SUBTREE
            tnode<type>* temp = tree->getRight();//this will be new root
            tnode<type>* bottom = getBottom(temp);// this left subtree goes to the bottom of the smallest right subtree node
            bottom->setLeft(tree->getLeft());   
            tree->setRight(NULL);
            tree->setLeft(NULL);
            delete tree;
            temp->setHeight(heightUpdate(temp));
            return temp;
        }
    }
    else if(tree->getItem() > item){ //item wasnt found so keep searching through tree
        tree->setLeft(delNode(tree->getLeft(), item));
    }
    else {
        tree->setRight(delNode(tree->getRight(), item));
        }
}

template <class type>
void avltree<type>::deleteNode(type item){ //primary function for deletion
    root = delNode(root, item);
}

template <class type>
int avltree<type>::max(int a, int b){ //needed for node height function
    if (a > b) return a;
    else return b;
}
template <class type>
int avltree<type>::heightUpdate(tnode<type>* tree){//returns the height of each node after inserting and deleting
    if (tree == NULL)return -1;
    else{
       return max(heightUpdate(tree->getLeft()),heightUpdate(tree->getRight())) + 1;
    }
}
#endif 
