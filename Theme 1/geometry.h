#pragma once
#include <iostream>
#include <cmath>
using namespace std;

// ЗАДАНИЕ 1

// Вектор на плоскости
struct Vector2
{
    double x;
    double y;
};

// Перечисление для квадранта
enum Quadrant { I = 1, II, III, IV, AXIS };

// Функции для векторов
Vector2 add(const Vector2& a, const Vector2& b);
Vector2 subtract(const Vector2& a, const Vector2& b);
void printVector(const Vector2& v);
Quadrant getQuadrant(const Vector2& v);


// ЗАДАНИЕ 2

// Комплексное число
struct ComplexNumber
{
    double re;
    double im;
};

// Перечисление для вида комплексного числа
enum ComplexType { REAL, IMAGINARY, COMPLEX };

// Функции для комплексных чисел
ComplexNumber add(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber multiply(const ComplexNumber& a, const ComplexNumber& b);
void printComplex(const ComplexNumber& c);
ComplexType getComplexType(const ComplexNumber& c);


// ЗАДАНИЕ 3

// Точка на плоскости
struct Point2
{
    double x;
    double y;
};

// Перечисление для вида треугольника
enum TriangleType { EQUILATERAL, ISOSCELES, SCALENE };

// Функции для точек и треугольников
void printPoint(const Point2& p);
double distance(const Point2& a, const Point2& b);
double perimeter(const Point2& a, const Point2& b, const Point2& c);
TriangleType getTriangleType(const Point2& a, const Point2& b, const Point2& c);