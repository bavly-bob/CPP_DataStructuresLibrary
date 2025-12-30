#include "../include/stack.h"
#include <iostream>

int main()
{
    ds::Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; // Should print 30
    std::cout << "Stack size: " << stack.size() << std::endl; // Should print 3

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should print 20
    std::cout << "Stack size after pop: " << stack.size() << std::endl; // Should print 2

    return 0;
}