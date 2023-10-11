#include "MyVector.h"

class Rect : public Shape {
    Vector ptLT, ptRB;
public:
    Rect();
    Rect(double left, double top, double right, double bottom);
    Rect(Vector v1, Vector v2);

    void Inflate(double inc = 1);
    void Inflate(double inc_width, double inc_height);
    void Inflate(double inc_left, double inc_top, double inc_right, double inc_bottom);

    void Out() override;
    void Move(Vector& v) override;
    double Area() override;
};
