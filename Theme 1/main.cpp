#include "geometry.h"

int main() {
    // ЗАДАНИЕ 1
    Vector2 v1{3, 4}, v2{-2, 1};
    Vector2 sum = add(v1, v2);
    Vector2 diff = subtract(v1, v2);
    cout << "Сумма векторов: "; printVector(sum);
    cout << "Разность векторов: "; printVector(diff);
    cout << "Квадрант v1: " << getQuadrant(v1) << endl;

    cout << endl;

    // ЗАДАНИЕ 2
    ComplexNumber c1{2.0, 3.0}, c2{1.0, -4.0};
    ComplexNumber csum = add(c1, c2);
    ComplexNumber cmul = multiply(c1, c2);
    cout << "Сумма комплексных: "; printComplex(csum);
    cout << "Произведение комплексных: "; printComplex(cmul);
    cout << "Тип числа c1: " << getComplexType(c1) << endl;

    cout << endl;

    // ЗАДАНИЕ 3
    Point2 A{0, 0}, B{3, 0}, C{1.5, sqrt(6.75)};
    cout << "Периметр треугольника: " << perimeter(A, B, C) << endl;
    cout << "Тип треугольника: " << getTriangleType(A, B, C) << endl;

    return 0;
}