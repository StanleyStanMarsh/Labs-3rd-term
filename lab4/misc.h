#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <iterator>

#include "MyVector.h"
#include "MyString.h"
#include "Rect.h"

typedef Vector Point;

template <class T> void pr(T& v, std::string s)
{
    std::cout<<"\n\n\t"<<s<<"  # Sequence:\n";

    // Итератор любого контейнера
    typename T::iterator p;
    int i;

    for (p = v.begin(), i=0;  p != v.end();  p++, i++)
        std::cout << std::endl << i+1 <<". "<< *p;
    std::cout << '\n';
}

template <class T> void pr2(T& v, std::string s) {
    std::cout<<"\n\n\t"<<s<<"  # Sequence:\n";

    int i = 1;
    while(!v.empty()) {
        std::cout << std::endl << i++ << ". " << v.top();
        v.pop();
    }
    std::cout << '\n';
}

template <class T> void pr2(std::queue<T>& v, std::string s) {
    std::cout<<"\n\n\t"<<s<<"  # Sequence:\n";

    int i = 1;
    while(!v.empty()) {
        std::cout << std::endl << i++ << ". " << v.front();
        v.pop();
    }
    std::cout << '\n';
}

bool pred(MyString s) { return (s.GetString()[0] == 'A' || s.GetString()[0] == 'a'); }

template <typename T> void pr3(T obj) {
    std::cout << obj << ' ';
}

class compareStr {
public:
    bool operator() (const char* s1, const char* s2)
    {
        if (strcmp(s1, s2) > 0)
            return true;
        return false;
    }
};

template <typename T>
class ChangeCoord
{
private:
    int x;
    int y;
public:
    ChangeCoord(int x_, int y_) : x(x_), y(y_) {}
    void operator()(T& obj) { obj.setX(x); obj.setY(y); }
};

class Pred1_1
{
private:
    int n;
    int m;
public:
    Pred1_1(int n_, int m_) : n(n_), m(m_) {}
    bool operator()(Point& obj) { return obj.getX() < m && obj.getX() > -n && obj.getY() < m && obj.getY() > -n; }
};

bool comp1(Rect r1, Rect r2) {
    return (sqrt(pow((r1.getRight() - r1.getLeft()) / 2, 2) + pow((r1.getTop() - r1.getBottom()) / 2, 2)) <
            sqrt(pow((r2.getRight() - r2.getLeft()) / 2, 2) + pow((r2.getTop() - r2.getBottom()) / 2, 2)));
}

std::string toLowerCase(std::string s) {
    std::transform(s.cbegin(), s.cend(), s.begin(),
                   [](char c) { return std::tolower(c); });
    return s;
}

int Shape::Count = 0;
Shape* Shape::shapes[] = { nullptr };