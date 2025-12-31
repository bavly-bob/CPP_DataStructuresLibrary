#include "stack.h"
#include <cstddef>
#include <stdexcept>


template <typename T>
ds::Stack<T>::Stack()
{
    size_t initialCapacity = 4;
    data = new T[initialCapacity];
    capacity = initialCapacity;
    topIndex = 0;
}

template <typename T>
ds::Stack<T>::~Stack()
{
    delete[] data;
}

template <typename T>
void ds::Stack<T>::resize(std::size_t newCapacity)
{
    T* newData = new T[newCapacity];
    for (std::size_t i = 0; i < topIndex; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;       // delete old memory
    data = newData;      // take ownership of new memory
    capacity = newCapacity;
}

template <typename T>
void ds::Stack<T>::push(const T& value)
{
    if (topIndex == capacity)
    {
        resize(capacity * 2);
    }
    data[topIndex++] = value;
}

template <typename T>
void ds::Stack<T>::pop()
{
    if (isEmpty())
        throw std::underflow_error("Stack is empty");
    --topIndex;
}

template <typename T>
T& ds::Stack<T>::top()
{
    if (isEmpty())
        throw std::underflow_error("Stack is empty");
    return data[topIndex - 1];
}

template <typename T>
const T& ds::Stack<T>::top() const
{
    if (isEmpty())
        throw std::underflow_error("Stack is empty");
    return data[topIndex - 1];
}

template <typename T>
bool ds::Stack<T>::isEmpty() const
{
    return topIndex == 0;
}

template <typename T>
std::size_t ds::Stack<T>::size() const
{
    return topIndex;
}