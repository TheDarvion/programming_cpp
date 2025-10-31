#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

// 2 ЗАДАНИЕ:

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Операторы сложения
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Деление на число
    Complex operator/(double value) const {
        return Complex(real / value, imag / value);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i)";
        return os;
    }
};

// Шаблон функции для суммы элементов массива
template <typename T>
T sumArray(T arr[], int size) {
    T sum = arr[0];
    for (int i = 1; i < size; ++i)
        sum = sum + arr[i];
    return sum;
}

// Шаблон функции для среднего арифметического
template <typename T>
T averageArray(T arr[], int size) {
    return sumArray(arr, size) / size;
}

#endif