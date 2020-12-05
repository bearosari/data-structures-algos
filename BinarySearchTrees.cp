#include <iostream>
#include <string>

typedef unsigned int uint;


// Node template class for binary trees
template <typename T>
class BTNode {
private:
    T data;
    BTNode<T> *left, *right;
public:
    BTNode(T data, BTNode<T> *left = nullptr, BTNode<T> *right = nullptr);
    template <typename T2> friend class BST;
};

template <typename T>
BTNode<T>::BTNode(T data, BTNode<T> *left, BTNode<T> *right) {
    this->data = data;
    this->left = left;
    this->right = right;
}


// Binary search tree template class
template <typename T>
class BST {
private:
    BTNode<T> *root; //pointer to node
    void delete_tree(BTNode<T> *root);
    void inorder(BTNode<T> *root);
    void preorder(BTNode<T> *root);
    void postorder(BTNode<T> *root);
public:
    BST(BTNode<T> *root);
    BST();
    ~BST();
    static BTNode<T> *test_init();
    void insert(T data);
    void display();
};

template <typename T>
BST<T>::BST(BTNode<T> *root) { 
    this->root = root;    //copies existing tree
} 

template <typename T>
BST<T>::BST() : root(nullptr) {} //default constructor 

template <typename T>
BST<T>::~BST(){
    this->delete_tree(this->root); //deletes entire tree
}

template <typename T>
BTNode<T> *BST<T>::test_init(){
    // bottom-up construction of tree
    BTNode<T> *n20 = new BTNode<int>(20);
    BTNode<T> *n40 = new BTNode<int>(40);
    BTNode<T> *n30 = new BTNode<int>(30, n20, n40);
    BTNode<T> *n0 = new BTNode<int>(0);
    BTNode<T> *n10 = new BTNode<int>(10, n0, n30);
    BTNode<T> *n90 = new BTNode<int>(90);
    BTNode<T> *n80 = new BTNode<int>(80, nullptr, n90);
    BTNode<T> *n60 = new BTNode<int>(60);
    BTNode<T> *n70 = new BTNode<int>(70, n60, n80);
    BTNode<T> *n50 = new BTNode<int>(50, n10, n70);
    return n50;
}

template <typename T>
void BST<T>::delete_tree(BTNode<T> *root){
// Put your answer here
}

template <typename T>
void BST<T>::display() {
    inorder(this->root);
    std::cout << '\n';
}

template <typename T>
void BST<T>::preorder(BTNode<T> *node) {
// define if needed
} 

template <typename T>
void BST<T>::inorder(BTNode<T> *node) {
    if (node!= NULL){
    inorder(node->left);
    std::cout <<node->data << " " <<std::endl;
    inorder(node->right);
}}


template <typename T>
void BST<T>::postorder(BTNode<T> *node) {
// define if needed
} 


template <typename T>
void BST<T>::insert(T data) {
// Put your answer here
    BTNode<T> *newnode= new BTNode<T>(data);
    BTNode<T> *x= this->root; 
    BTNode<T> *y = NULL; 
  
    while (x != NULL) { 
        y = x; 
        if (data < x->data) 
            x = x->left; 
        else
            x = x->right; 
    } 
    
  
    if (data < y->data){ 
        y->left = newnode; 
    }
    else{
        y->right = newnode; 
    }
} 




int main() {
    BST<int> bst(BST<int>::test_init());
    bst.display();
    bst.insert(-65);
    bst.insert(35);
    bst.insert(90);
    bst.display();
    return 0;
}
