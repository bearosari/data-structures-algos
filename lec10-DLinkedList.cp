#include <iostream>
#include <string>

typedef unsigned int uint;



// Node template class for doubly-linked lists
template <typename T>
class DNode {
private:
    T data;
    DNode<T> *prev, *next;
public:
    DNode(T data, DNode<T> *prev = nullptr, DNode<T> *next = nullptr);
    template <typename T2> friend class DLinkedList;    // gives DNode object private access to template class DLinkedList
};

template <typename T>
DNode<T>::DNode(T data, DNode<T> *prev, DNode<T> *next) {
    this->data = data;
    this->prev = prev;
    this->next = next;
}



// Doubly-linked list template class
template <typename T>
class DLinkedList {
private:
    DNode<T> *head, *tail;
    uint size;
    DNode<T> *gotoNode(uint pos, std::string dir = "forward");
    T erase(DNode<T> *node);
public:
    DLinkedList();
    ~DLinkedList();
    uint getSize() { return size; };
    T at(uint pos);
    void insertFront(T data, uint pos = 0);
    T eraseFront(uint pos = 0);
    void insertBack(T data, uint pos = 0);
    T eraseBack(uint pos = 0);
};

// Default constructor creates empty nodes for the head and tail of the doubly-linked list
template <typename T>
DLinkedList<T>::DLinkedList() {
    this->head = new DNode<T>(T{}); // head and tail nodes are both set 
    this->tail = new DNode<T>(T{}); //   to have default value of T
    this->head->next = this->tail;  // point the head and tail towards
    this->tail->prev = this->head;  //   each other
    this->size = 0;
}

// Default destructor calls erase for all nodes then deletes the head and tail
template <typename T>
DLinkedList<T>::~DLinkedList() {    
    T erased{};
    while(size != 0) {
        erased = this->eraseFront();
        std::cout << "deleted Node(" << erased << ")\n";
    }
    delete this->head;
    delete this->tail;
}

// Traverses the list and returns a pointer to the (pos-1)th node
//   either from the head (default) or from the tail
template <typename T>
DNode<T> *DLinkedList<T>::gotoNode(uint pos, std::string dir){
    DNode<T> *curNode;
    if(!dir.compare("forward")) {
        curNode = this->head;
        for(uint i = 0; i < pos+1; ++i) {
            curNode = curNode->next;
        } 
    } else if(!dir.compare("backward")) {
        curNode = this->tail;
        for(uint i = 0; i < pos+1; ++i) {
            curNode = curNode->prev;
        } 
    }
    return curNode;   
}

template <typename T>
T DLinkedList<T>::erase(DNode<T> *node) {
    T val = node->data;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --(this->size);
    return val;    
}

// Returns the data contained within the (pos)th node starting from
//   the head or tail, depending on which is nearer
template <typename T>
T DLinkedList<T>::at(uint pos) {
    DNode<T> *curNode;
    uint N = this->getSize();
    if(pos <= N/2) {
        curNode = gotoNode(pos-1);
        return curNode->next->data;
    } else {
        curNode = gotoNode(N-1-pos-1, "backward");
        return curNode->prev->data;
    }
}

// Inserts data at the (pos)th node starting from the head
template <typename T>
void DLinkedList<T>::insertFront(T data, uint pos) {
    DNode<T> *curNode = gotoNode(pos);
    curNode->prev = curNode->prev->next = new DNode<T>(data, curNode->prev, curNode);
    ++(this->size);
}

// Erases data at the (pos)the node starting from the head
template <typename T>
T DLinkedList<T>::eraseFront(uint pos) {
    DNode<T> *curNode = gotoNode(pos);
    return erase(curNode);
}

// Inserts data at the (pos)th node starting from the tail
template <typename T>
void DLinkedList<T>::insertBack(T data, uint pos) {
    DNode<T> *curNode = gotoNode(pos, "backward");
    curNode->next = curNode->next->prev = new DNode<T>(data, curNode, curNode->next);
    ++(this->size);
}

// Erases data at the (pos)the node starting from the tail
template <typename T>
T DLinkedList<T>::eraseBack(uint pos) {
    DNode<T> *curNode = gotoNode(pos, "backward");
    return erase(curNode);
}



int main() {
    
    DLinkedList<int> dlist;
    dlist.insertFront(10);
    dlist.insertFront(92, 1);
    dlist.insertFront(38, 2);
    dlist.insertBack(101);
    dlist.insertBack(56, 1);
    dlist.insertBack(74, 2);
    std::cout << "Doubly-linked list size: " << dlist.getSize() << std::endl;
    for(uint i = 0; i < dlist.getSize(); ++i) { // Don't iterate the at() method for actual list traversal 
        std::cout << dlist.at(i) << std::endl;
    }

    int erased1 = dlist.eraseFront(1);
    std::cout << "deleted Node(" << erased1 << ")\n";
    int erased2 = dlist.eraseBack(1);
    std::cout << "deleted Node(" << erased2 << ")\n";

    std::cout << "Doubly-linked list size: " << dlist.getSize() << std::endl;
    for(uint i = 0; i < dlist.getSize(); ++i) {
        std::cout << dlist.at(i) << std::endl;
    }

}