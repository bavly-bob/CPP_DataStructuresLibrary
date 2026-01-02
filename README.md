# CPP_DataStructuresLibrary
A C++ library of core data structures and algorithms, built from scratch with testing and usage examples.

# Stack Library (C++)

A lightweight, type-safe **Stack (LIFO) data structure** implemented in modern C++.  
Designed for **learning, correctness, and clean architecture**, with unit tests and clear separation of interface and implementation.

---

## 🚀 Features

- Generic **template-based** implementation (`Stack<T>`)
- Strong **type safety**
- Clean and minimal API (`push`, `pop`, `top`, `empty`, `size`)
- Exception-safe operations
- Unit tests included
- Clear project structure (headers, sources, tests)
- Compatible with **C++17 and later**

---

## 📂 Project Structure

```text
.
├── include/
│   ├── stack.h        # Stack interface (template declaration)
│   ├── tests_stack.h  # Stack tests functions 
│   └── stack.tpp      # Stack implementation (template definitions)
├── src/
│   
├── tests/
│   └── tests_stack.cpp
├── main.cpp
└── README.md
