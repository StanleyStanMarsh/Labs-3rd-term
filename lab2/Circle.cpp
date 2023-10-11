#include "Circle.h"
#include <math.h>
#include <iostream>

Circle::Circle(Vector v, double r) {
    ptCntr = v;
    R = r;
}

void Circle::Out() {
    std::cout << "\nCircle (" << ptCntr.getX() << ptCntr.getY() << ")";
}

void Circle::Move(Vector &v) {
    ptCntr.setX(ptCntr.getX() + v.getX());
    ptCntr.setY(ptCntr.getY() + v.getY());
}

double Circle::Area() {
    return M_PI * R * R;
}

Circle::Circle(double x, double y, double r) {
    ptCntr.setX(x);
    ptCntr.setY(y);
    R = r;
}

