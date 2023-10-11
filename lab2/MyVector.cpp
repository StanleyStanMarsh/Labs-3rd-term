#include "stdafx.h"
#include "MyVector.h"


Vector::Vector (double c1, double c2)
{
	x=c1;   y=c2;
//    Count++;
}

Vector::Vector ()
{
	x = y = 0.;
//    Count++;
}

void Vector::Out()
{
	cout << "\nVector:  x = " << x << ",  y = " << y;
}

//====== Переопределение операций =====//
Vector& Vector::operator= (const Vector& v)	// Присвоение
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}

Vector::Vector(const Vector &v) {
    *this = v;
//    Count++;
}

Vector Vector::operator+(const Vector &v) const {
    return Vector(this->x + v.x, this->y + v.y);
}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

bool Vector::operator>(const Vector &v) const {
    if (!*this > !v) return true;
    return false;
}

bool Vector::operator==(const Vector &v) const {
    if (fabs(this->x - v.x) < DBL_EPSILON && fabs(this->y - v.y) < DBL_EPSILON) return true;
    return false;
}

Vector Vector::operator*(double d) const {
    return Vector(this->x * d, this->y * d);
}

Vector operator*(double d, const Vector &v) {
    return Vector(v.x * d, v.y * d);
}

//double operator*(const Vector &v1, const Vector &v2) {
//    return v1.x * v2.x + v1.y * v2.y;
//}

double operator! (const Vector& v) {
    return sqrt(v.getX() * v.getX() + v.getY() * v.getY());
}

void Vector::setX(double x) {
    this->x = x;
}

void Vector::setY(double y) {
    this->y = y;
}

double Vector::operator*(const Vector &v2) const {
    return this->x * v2.x + this->y * v2.y;
}


