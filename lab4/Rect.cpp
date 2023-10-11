#include <iostream>
#include "Rect.h"

Rect::Rect(double left, double top, double right, double bottom) {
    ptLT.setX(left);
    ptLT.setY(top);
    ptRB.setX(right);
    ptRB.setY(bottom);
}

Rect::Rect() {
    ptLT.setX(0);
    ptLT.setY(0);
    ptRB.setX(0);
    ptRB.setY(0);
}

Rect::Rect(Vector v1, Vector v2) {
    ptLT = v1;
    ptRB = v2;
}

void Rect::Inflate(double inc) {
    ptLT.setX(ptLT.getX() - inc);
    ptLT.setY(ptLT.getY() + inc);
    ptRB.setX(ptRB.getX() + inc);
    ptRB.setY(ptRB.getY() - inc);
}

void Rect::Inflate(double inc_width, double inc_height) {
    ptLT.setX(ptLT.getX() - inc_width);
    ptRB.setX(ptRB.getX() + inc_width);
    ptLT.setY(ptLT.getY() + inc_height);
    ptRB.setY(ptRB.getY() - inc_height);
}

void Rect::Inflate(double inc_left, double inc_top, double inc_right, double inc_bottom) {
    ptLT.setX(ptLT.getX() - inc_left);
    ptRB.setX(ptRB.getX() + inc_right);
    ptLT.setY(ptLT.getY() + inc_top);
    ptRB.setY(ptRB.getY() - inc_bottom);
}

void Rect::Out() {
    std::cout << "\nRect (" << ptLT.getX() << ", " << ptLT.getY() << ", " <<
              ptRB.getX() << ", " << ptRB.getY() << ")";
}

void Rect::Move(Vector &v) {
    ptLT.setX(ptLT.getX() + v.getX());
    ptRB.setX(ptRB.getX() + v.getX());
    ptLT.setY(ptLT.getY() + v.getY());
    ptRB.setY(ptRB.getY() + v.getY());
}

double Rect::Area() {
    return (std::abs(ptRB.getX() - ptLT.getX())) * (std::abs(ptLT.getY() - ptRB.getY()));
}

std::ostream &operator<<(std::ostream &out, const Rect &r) {
    out << "\nRect(" << r.getLeft() << ", " << r.getTop() << ", " << r.getRight() << ", " << r.getBottom() << ")";
}