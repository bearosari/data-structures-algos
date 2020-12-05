//BEA ROSARI B SUPANGA
//2018-10282

#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std; 
  
template <typename T>
class DQ { 
    public:
    stack<T> stack; 
    queue<T> queue; 
    
    void push(T val) 
    { 
        while (!queue.empty()) 
    { 
        stack.push(queue.front()); 
        queue.pop();
    }
        while (!stack.empty()) 
    { 
        queue.push(stack.top()); 
        stack.pop();
    }
        while (!queue.empty()) 
    { 
        stack.push(queue.front()); 
        queue.pop();
    }
        stack.push(val);
        while (!stack.empty()) 
    { 
        queue.push(stack.top()); 
        stack.pop();
    }
    } 

  
    void pop()
    {
        queue.pop();

    }

    void eject() 
    { 
        while (!queue.empty()) 
    { 
        stack.push(queue.front()); 
        queue.pop();
    }
        stack.pop();
        while (!stack.empty()) 
    { 
        queue.push(stack.top()); 
        stack.pop();
    }
        while (!queue.empty()) 
    { 
        stack.push(queue.front()); 
        queue.pop();
    }
        while (!stack.empty()) 
    { 
        queue.push(stack.top()); 
        stack.pop();
    }
    } 
    
    void inject(T val)
    {
        queue.push(val);
    }

    void display()
    {  
        ::queue<T> container;
        container=queue;
        while (!container.empty())
    {
        cout << container.front() << endl;
        container.pop();
    }

    }

}; 
  
int main() 
{ 
    DQ<int> q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    q.pop();
    q.display();
    q.eject();
    q.display();
    q.inject(5);
    q.display();
    return 0; 
} 