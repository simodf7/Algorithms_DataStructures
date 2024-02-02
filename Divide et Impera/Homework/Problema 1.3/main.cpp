#include <iostream>
using namespace std; 


struct Node{
    int key; 
    int priority; 
    Node* parent;
    Node* left;
    Node* right;  

    Node(int k): key(k), left(nullptr), right(nullptr), parent{nullptr}{
        this->priority = rand() % 1000;
    }
};


Node* rotate_left(Node* y){
    Node* dad = y->parent; 
    Node* grand = dad->parent; 
    grand->
}



int main(){



    return 1;
}