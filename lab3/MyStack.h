#pragma once
#include <iostream>
#include <exception>

class StackOverflow : public std::exception {
private:
    const char* reason;
public:
    StackOverflow() : reason("Stack Overflow") {}
};

class StackUnderflow : public std::exception {
private:
    const char* reason;
public:
    StackUnderflow() : reason("Stack Underflow") {}
};

class StackOutOfRange : public std::exception {
private:
    const char* reason;
public:
    StackOutOfRange() : reason("StackOutOfRange") {}
    void Out() const { std::cerr << reason; }
};

template <class Type, int c>
class MyStack {
    static const int STACK_MAX_SIZE = 10000;
    Type* array;
    int capacity; // количество выделяемой памяти
    int top;
public:
    MyStack();
    ~MyStack();

    int GetSize() { return top + 1; }
    void Push(Type x);
    Type Pop();
    int Capacity() { return capacity; }

    Type& operator[](int i);

    bool IsFull() { return top == capacity - 1; }
    bool IsEmpty() { return top == -1; }
};

template<class Type, int c>
Type &MyStack<Type, c>::operator[](int i) {
    if (i > top || IsEmpty())
        throw StackOutOfRange();
    return array[i];
}

template <class Type, int c>
Type MyStack<Type, c>::Pop() {
    if (IsEmpty()) {
        throw StackUnderflow();
    }
    return array[top--];
}

template <class Type, int c>
void MyStack<Type, c>::Push(Type x) {
    if (IsFull()) {
        throw StackOverflow();
    }
    top++;
    array[top] = x;
}

template <class Type, int c>
MyStack<Type, c>::MyStack() : top(-1) {
    if (c > STACK_MAX_SIZE) {
        array = new  Type[STACK_MAX_SIZE];
        capacity = STACK_MAX_SIZE;
        return;
    }
    array = new Type[c];
    capacity = c;
}

template <class Type, int c>
MyStack<Type, c>::~MyStack() {
    delete[] array;
}