#pragma once
#include <list>

class Vector;
class Shape {
    static int Count;
public:
    static Shape* shapes[1000];

    static int GetCount();
    Shape();
    ~Shape();
    static void PrintCount();
    virtual void Move (Vector& v) = 0;
    virtual void Out() = 0;
    virtual double Area() = 0;
};