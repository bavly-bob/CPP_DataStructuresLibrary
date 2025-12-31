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

// the rule of 5 implementations would go here

template <typename T>
ds::Stack<T>::~Stack()
{
    delete[] data;
}

template <typename T>
ds::Stack<T>::Stack(const Stack& other)
    : capacity(other.capacity), topIndex(other.topIndex)
{
    data = new T[capacity];
    for (std::size_t i = 0; i < topIndex; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
ds::Stack<T>& ds::Stack<T>::operator=(const Stack& other)
{
    if(this != &other)
    {
        delete[] data;
        capacity = other.capacity;
        topIndex = other.topIndex;
        data = new T[capacity];
        for (std::size_t i = 0; i < topIndex; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
ds::Stack<T>::Stack(Stack&& other) noexcept
    : data(other.data), capacity(other.capacity), topIndex(other.topIndex)
{
    other.data = nullptr;
    other.capacity = 0;
    other.topIndex = 0;
}

template <typename T>
ds::Stack<T>& ds::Stack<T>::operator=(Stack&& other) noexcept
{
    if(this != &other)
    {
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        topIndex = other.topIndex;

        other.data = nullptr;
        other.capacity = 0;
        other.topIndex = 0;
    }
    return *this;
}