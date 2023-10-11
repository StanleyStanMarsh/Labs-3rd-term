#include "Shape.h"
#include "MyVector.h"

class Circle : public Shape {
    Vector ptCntr;
    double R;
public:
    Circle(Vector v, double r);
    Circle(double x, double y, double r);

    void Out() override;
    void Move(Vector& v) override;
    double Area() override;
};
