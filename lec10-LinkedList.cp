#include <iostream>

typedef unsigned int uint;



// Node template class for linked lists
template <typename T>
class Node {
private:
    T data;
    Node<T> *next;
public:
    Node(T data, Node<T> *next = nullptr);
    template <typename T2> friend class LinkedList; // gives Node object private access to template class LinkedList
};

template <typename T>
Node<T>::Node(T data, Node<T> *next) {
    this->data = data;
    this->next = next;
}



// Linked list template class
template <typename T>
class LinkedList {
private:
    Node<T> *head;
    uint size;
    Node<T> *gotoNode(uint pos);
public:
    LinkedList();
    ~LinkedList();
    uint getSize() { return size; };
    T at(uint pos);
    void insert(T data, uint pos = 0);
    T erase(uint pos = 0);
};

// Default constructor creates an empty node as the head of the linked list
template <typename T>
LinkedList<T>::LinkedList() {
    this->head = new Node<T>(T{});  // head node is set to have default value of T
    this->size = 0;
}

// Default destructor calls erase for all nodes then deletes the head
template <typename T>
LinkedList<T>::~LinkedList() {
    T erased{};
    while(size != 0) {
        erased = this->erase();
        std::cout << "deleted Node(" << erased << ")\n";
    }
    delete this->head;
}

// Traverses the list and returns a pointer to the (pos-1)th node from the head
template <typename T>
Node<T> *LinkedList<T>::gotoNode(uint pos){
    Node<T> *curNode = this->head;
    for(uint i = 0; i < pos+1; ++i) {
        curNode = curNode->next;
    } 
    return curNode;   
}

// Returns the data contained within the (pos)th node starting from the head
template <typename T>
T LinkedList<T>::at(uint pos) {
    Node<T> *curNode = gotoNode(pos);   // go to (pos-1)th node
    return curNode->data;         // return data in (pos)th node
}

// Inserts data at the (pos)th node starting from the head
template <typename T>
void LinkedList<T>::insert(T data, uint pos) {
    Node<T> *curNode = gotoNode(pos-1);
    curNode->next = new Node<T>(data, curNode->next); 
    ++(this->size);
}

// Erases data at the (pos)the node starting from the head
template <typename T>
T LinkedList<T>::erase(uint pos) {
    Node<T> *curNode = gotoNode(pos-1);
    Node<T> *nxtNode = curNode->next;
    T val = nxtNode->data;
    curNode->next = nxtNode->next;
    delete nxtNode;
    --(this->size);
    return val;
}



int main() {

    LinkedList<int> list;
    list.insert(10);
    list.insert(92, 1);
    list.insert(38, 2);
    list.insert(74, 3);
    list.insert(56, 4);
    std::cout << "Linked list size: " << list.getSize() << std::endl;
    for(uint i = 0; i < list.getSize(); ++i) {  // Don't iterate the at() method for actual list traversal 
        std::cout << list.at(i) << std::endl;
    }

    int erased = list.erase(2);
    std::cout << "deleted Node(" << erased << ")\n";

    std::cout << "Linked list size: " << list.getSize() << std::endl;
    for(uint i = 0; i < list.getSize(); ++i) {
        std::cout << list.at(i) << std::endl;
    }

}