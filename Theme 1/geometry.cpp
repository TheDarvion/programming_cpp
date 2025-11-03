#include "geometry.h"

// ЗАДАНИЕ 1

Vector2 add(const Vector2& a, const Vector2& b) {
    return { a.x + b.x, a.y + b.y };
}

Vector2 subtract(const Vector2& a, const Vector2& b) {
    return { a.x - b.x, a.y - b.y };
}

void printVector(const Vector2& v) {
    cout << "(" << v.x << ", " << v.y << ")" << endl;
}

Quadrant getQuadrant(const Vector2& v) {
    if (v.x > 0 && v.y > 0) return I;
    if (v.x < 0 && v.y > 0) return II;
    if (v.x < 0 && v.y < 0) return III;
    if (v.x > 0 && v.y < 0) return IV;
    return AXIS;
}


// ЗАДАНИЕ 2

ComplexNumber add(const ComplexNumber& a, const ComplexNumber& b) {
    return { a.re + b.re, a.im + b.im };
}

ComplexNumber multiply(const ComplexNumber& a, const ComplexNumber& b) {
    return {
        a.re * b.re - a.im * b.im,
        a.re * b.im + a.im * b.re
    };
}

void printComplex(const ComplexNumber& c) {
    cout << c.re << " + i*" << c.im << endl;
}

ComplexType getComplexType(const ComplexNumber& c) {
    if (c.im == 0) return REAL;
    if (c.re == 0) return IMAGINARY;
    return COMPLEX;
}


// ЗАДАНИЕ 3

void printPoint(const Point2& p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

double distance(const Point2& a, const Point2& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double perimeter(const Point2& a, const Point2& b, const Point2& c) {
    return distance(a, b) + distance(b, c) + distance(c, a);
}

TriangleType getTriangleType(const Point2& a, const Point2& b, const Point2& c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);

    const double eps = 1e-6;
    bool ab_eq_bc = fabs(ab - bc) < eps;
    bool bc_eq_ca = fabs(bc - ca) < eps;
    bool ca_eq_ab = fabs(ca - ab) < eps;

    if (ab_eq_bc && bc_eq_ca) return EQUILATERAL;
    if (ab_eq_bc || bc_eq_ca || ca_eq_ab) return ISOSCELES;
    return SCALENE;
}