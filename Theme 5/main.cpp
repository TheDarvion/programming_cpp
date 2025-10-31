#include <iostream>
#include "fraction.h"
#include "complex.h"

int main() {

    // 1 ЗАДАНИЕ: Fraction

    cout << "1 ЗАДАНИЕ:\n" << endl;

    int intArr[] = {1, 5, 3, 7, 2};
    int intSize = sizeof(intArr)/sizeof(intArr[0]);
    int intVal = 4;
    cout << "Целые числа меньше " << intVal << ": " << countLess(intArr, intSize, intVal) << endl;
    cout << "Целые числа больше " << intVal << ": " << countGreater(intArr, intSize, intVal) << endl << endl;

    Fraction fracArr[] = {Fraction(1,2), Fraction(3,4), Fraction(2,3), Fraction(5,6)};
    int fracSize = sizeof(fracArr)/sizeof(fracArr[0]);
    Fraction fracVal(1,2);
    cout << "Дроби меньше " << fracVal << ": " << countLess(fracArr, fracSize, fracVal) << endl;
    cout << "Дроби больше " << fracVal << ": " << countGreater(fracArr, fracSize, fracVal) << endl << endl;

    double doubleArr[] = {1.5, 2.7, 0.3, 4.8};
    int doubleSize = sizeof(doubleArr)/sizeof(doubleArr[0]);
    double doubleVal = 2.0;
    cout << "Дробные числа меньше " << doubleVal << ": " << countLess(doubleArr, doubleSize, doubleVal) << endl;
    cout << "Дробные числа больше " << doubleVal << ": " << countGreater(doubleArr, doubleSize, doubleVal) << endl << endl;


    // 2 ЗАДАНИЕ: Complex

    cout << "2 ЗАДАНИЕ:\n" << endl;

    int intArr2[] = {1, 2, 3, 4, 5};
    int intSize2 = sizeof(intArr2)/sizeof(intArr2[0]);
    cout << "Сумма целых чисел: " << sumArray(intArr2, intSize2) << endl;
    cout << "Среднее целых чисел: " << averageArray(intArr2, intSize2) << endl << endl;

    double doubleArr2[] = {1.5, 2.5, 3.5};
    int doubleSize2 = sizeof(doubleArr2)/sizeof(doubleArr2[0]);
    cout << "Сумма дробных чисел: " << sumArray(doubleArr2, doubleSize2) << endl;
    cout << "Среднее дробных чисел: " << averageArray(doubleArr2, doubleSize2) << endl << endl;

    Complex complexArr[] = {Complex(1,2), Complex(3,4), Complex(-1,1)};
    int complexSize = sizeof(complexArr)/sizeof(complexArr[0]);
    cout << "Сумма комплексных чисел: " << sumArray(complexArr, complexSize) << endl;
    cout << "Среднее комплексных чисел: " << averageArray(complexArr, complexSize) << endl;

    return 0;
}