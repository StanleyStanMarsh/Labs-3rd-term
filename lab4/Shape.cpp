#include <iostream>
#include "Shape.h"

void Shape::PrintCount() {
    std::cout << "\n Now there are " << Count << " vectors\n";
}

Shape::Shape() {
    Count++;
    shapes[Count - 1] = this;
}

Shape::~Shape() {
    bool flag = false;
    Count--;
    for (int i = 0; i < Count; i++) {
        if (shapes[i] == this) flag = true;
        if (flag) {
            shapes[i] = shapes[i + 1];
        }
    }
}

int Shape::GetCount() {
    return Count;
}
