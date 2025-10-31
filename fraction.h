#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

// 1 ЗАДАНИЕ:

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int a = numerator, b = denominator;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        numerator /= a;
        denominator /= a;
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) denominator = 1;
        simplify();
    }

    // Операторы сравнения
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

// Шаблоны функций для 1 задания
template <typename T>
int countLess(T arr[], int size, T value) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] < value) count++;
    return count;
}

template <typename T>
int countGreater(T arr[], int size, T value) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] > value) count++;
    return count;
}

#endif