#include<iostream>
#include"avltree.h"
using namespace std;
int main(){
avltree<int> myTree;
myTree.insert(7);
myTree.insert(5);
myTree.insert(28);
myTree.insert(55);
myTree.insert(1);
myTree.insert(2);
if (myTree.isEmpty()) cout<< "tree is empty\n";
else cout << "not empty\n"; 
myTree.display();
cout << "Deleting node containing 28\n";
myTree.deleteNode(28);
myTree.display();
}
