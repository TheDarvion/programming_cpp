#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Задание 1: Плоские фигуры

// Базовый класс для плоских фигур
class GeometricFigure {
public:
    virtual double area() const = 0;        // Площадь фигуры
    virtual double perimeter() const = 0;   // Периметр фигуры
    virtual void print(ostream &out) const = 0;  // Вывод информации о фигуре
    virtual ~GeometricFigure() {}           // Виртуальный деструктор
};

// Треугольник
class Triangle : public GeometricFigure {
private:
    double a, b, c; // стороны треугольника
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double perimeter() const override {      // Вычисление периметра
        return a + b + c;
    }

    double area() const override {           // Вычисление площади по формуле Герона
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void print(ostream &out) const override { // Вывод информации о треугольнике
        out << "Треугольник (стороны: " << a << ", " << b << ", " << c << ")";
    }
};

// Круг
class Circle : public GeometricFigure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double perimeter() const override {      // Периметр круга
        return 2 * M_PI * radius;
    }

    double area() const override {           // Площадь круга
        return M_PI * radius * radius;
    }

    void print(ostream &out) const override { // Вывод информации о круге
        out << "Круг (радиус: " << radius << ")";
    }
};

// Прямоугольник
class Rectangle : public GeometricFigure {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double perimeter() const override {      // Периметр прямоугольника
        return 2 * (width + height);
    }

    double area() const override {           // Площадь прямоугольника
        return width * height;
    }

    void print(ostream &out) const override { // Инфо о прямоугольнике
        out << "Прямоугольник (ширина: " << width << ", высота: " << height << ")";
    }
};

// Перегрузка оператора вывода для плоской фигуры
ostream& operator<<(ostream &out, const GeometricFigure &fig) {
    fig.print(out);
    return out;
}

// Задание 2: Объёмные фигуры

// Базовый класс для объёмных фигур
class SolidFigure {
public:
    virtual double volume() const = 0;            // Объём фигуры
    virtual double surfaceArea() const = 0;       // Площадь поверхности
    virtual void print(ostream &out) const = 0;   // Вывод информации о фигуре
    virtual ~SolidFigure() {}

    // Перегрузка операторов сравнения по объёму
    bool operator<(const SolidFigure &other) const { return volume() < other.volume(); }
    bool operator>(const SolidFigure &other) const { return volume() > other.volume(); }
    bool operator==(const SolidFigure &other) const { return volume() == other.volume(); }
};

// Шар
class Sphere : public SolidFigure {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {}

    double volume() const override {                 // Объём шара
        return (4.0 / 3) * M_PI * pow(radius, 3);
    }

    double surfaceArea() const override {           // Площадь поверхности шара
        return 4 * M_PI * radius * radius;
    }

    void print(ostream &out) const override {       // Инфо о шаре
        out << "Шар (радиус: " << radius << ")";
    }
};

// Куб
class Cube : public SolidFigure {
private:
    double side;
public:
    Cube(double s) : side(s) {}

    double volume() const override {                // Объём куба
        return pow(side, 3);
    }

    double surfaceArea() const override {           // Площадь поверхности куба
        return 6 * side * side;
    }

    void print(ostream &out) const override {       // Инфо о кубе
        out << "Куб (сторона: " << side << ")";
    }
};

// Цилиндр
class Cylinder : public SolidFigure {
private:
    double radius, height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double volume() const override {                // Объём цилиндра
        return M_PI * radius * radius * height;
    }

    double surfaceArea() const override {           // Площадь поверхности цилиндра
        return 2 * M_PI * radius * (radius + height);
    }

    void print(ostream &out) const override {       // Инфо о цилиндре
        out << "Цилиндр (радиус: " << radius << ", высота: " << height << ")";
    }
};

// Перегрузка оператора вывода для объёмной фигуры
ostream& operator<<(ostream &out, const SolidFigure &fig) {
    fig.print(out);
    return out;
}

// Главная функция
// Демонстрирует работу полиморфизма, виртуальных методов и перегрузки операторов

int main() {
    // Задание 1
    cout << " Плоские фигуры\n";
    vector<GeometricFigure*> flatFigures;
    flatFigures.push_back(new Triangle(3,4,5));
    flatFigures.push_back(new Circle(2));
    flatFigures.push_back(new Rectangle(4,6));

    // Вывод информации о всех плоских фигурах
    for (auto fig : flatFigures) {
        cout << *fig << "\n";
        cout << "Периметр: " << fig->perimeter() << ", Площадь: " << fig->area() << "\n\n";
    }

    // Очистка памяти
    for (auto fig : flatFigures) delete fig;

    // Задание 2
    cout << " Объёмные фигуры\n";
    vector<SolidFigure*> solidFigures;
    solidFigures.push_back(new Sphere(3));
    solidFigures.push_back(new Cube(2));
    solidFigures.push_back(new Cylinder(2,5));

    // Вывод информации о всех объёмных фигурах
    for (auto fig : solidFigures) {
        cout << *fig << "\n";
        cout << "Объём: " << fig->volume() << ", Площадь поверхности: " << fig->surfaceArea() << "\n\n";
    }

    // Демонстрация сравнения объёмов
    if (*solidFigures[0] > *solidFigures[1]) cout << "Шар больше куба по объёму\n";
    if (*solidFigures[2] < *solidFigures[0]) cout << "Цилиндр меньше шара по объёму\n";

    // Очистка памяти
    for (auto fig : solidFigures) delete fig;

    return 0;
}