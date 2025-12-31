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

    ds::Stack<int> copiedStack = stack; // Test copy constructor
    std::cout << "Top element of copied stack: " << copiedStack.top() << std::endl; // Should print 20
    std::cout << "Copied stack size: " << copiedStack.size() << std::endl; // Should print 2

    ds::Stack<int> movedStack = std::move(stack); // Test move constructor
    std::cout << "Top element of moved stack: " << movedStack.top() <<
    std::cout << "Moved stack size: " << movedStack.size() << std::endl; // Should print 2
    std::cout << "Original stack size after move: " << stack.size() << std::endl; // Should print 0
    return 0;
}