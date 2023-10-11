#pragma once
#include <float.h>
#include "stdafx.h"
#include "Shape.h"

class Vector : public Shape
{
private:
	double x, y;	// Координаты вектора на плоскости
public:
	//========== Три конструктора
	Vector (double c1, double c2);
	Vector ();							// Default
	Vector(const Vector &v);
	//====== Переопределение операций =====//
    Vector& operator= (const Vector& v);	// Присвоение
    Vector operator+ (const Vector& v) const;

    bool operator> (const Vector& v) const;
    bool operator< (const Vector& v) const;
    bool operator== (const Vector& v) const;
    friend std::ostream &operator<<(ostream &out, const Vector &v);

    friend double operator! (const Vector& v);
    Vector operator* (double d) const;
    friend Vector operator* (double d, const Vector& v);
    friend double operator* (const Vector& v1, const Vector& v2);

	void Out();
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);

    void Move(Vector &v) override { x += v.x; y += v.y; };
    double Area() override { return 0; };
};

