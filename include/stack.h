#ifndef CPP_DATASTRUCTURESLIBRARY_STACK_H
#define CPP_DATASTRUCTURESLIBRARY_STACK_H

#include <cstddef>
#include <stdexcept>

namespace ds
{
    template <typename T>
    class Stack
    {
    private:
        T* data;
        std::size_t capacity;
        std::size_t topIndex;
        void resize(std::size_t newCapacity);
    
    public:
        Stack();
        ~Stack();

        // rule of 5 
        Stack(const Stack& other);
        Stack& operator=(const Stack& other);
        Stack(Stack&& other) noexcept;
        Stack& operator=(Stack&& other) noexcept;

        // main operations
        void push(const T& value);
        void pop();
        T& top();
        const T& top() const; 
        bool isEmpty() const;
        std::size_t size() const;
    };
}

#include "stack.tpp"
#endif //CPP_DATASTRUCTURESLIBRARY_STACK_H
