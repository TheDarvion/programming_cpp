#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Структура для представления точки на плоскости
struct Point {
    double x, y;
    Point(double x_, double y_) : x(x_), y(y_) {}
};

// Функция вычисления расстояния между двумя точками
double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Задание 1: Поиск максимального расстояния (диаметра)
mutex mtx_distance;
double global_max_dist = 0.0;

/**
 * Функция потока для поиска максимального расстояния
 * Обрабатывает точки в диапазоне [start, end)
 */
void find_max_distance(const vector<Point>& points, int start, int end) {
    double local_max = 0.0;

    for (int i = start; i < end; ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double dist = distance(points[i], points[j]);
            if (dist > local_max) {
                local_max = dist;
            }
        }
    }

    lock_guard<mutex> lock(mtx_distance);
    if (local_max > global_max_dist) {
        global_max_dist = local_max;
    }
}

/**
 * Основная функция для задания 1
 * Находит максимальное расстояние между точками множества
 */
double task1_diameter(const vector<Point>& points, int num_threads) {
    cout << "\nЗАДАНИЕ 1: Поиск максимального расстояния между точками (диаметра)" << endl;

    global_max_dist = 0.0;
    auto start = high_resolution_clock::now();

    vector<thread> threads;
    int chunk_size = points.size() / num_threads;

    // Создание и запуск потоков
    for (int t = 0; t < num_threads; ++t) {
        int start_idx = t * chunk_size;
        int end_idx = (t == num_threads - 1) ? points.size() : start_idx + chunk_size;
        threads.push_back(thread(find_max_distance, cref(points), start_idx, end_idx));
    }

    // Ожидание завершения потоков
    for (auto& th : threads) {
        th.join();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Максимальное расстояние (диаметр множества): " << global_max_dist << endl;
    cout << "Время выполнения: " << duration.count() << " мс" << endl;
    cout << "Количество потоков: " << num_threads << endl;

    return global_max_dist;
}

// Задание 2: Поиск точки с максимальным потенциалом
mutex mtx_potential;
double global_max_potential = -1.0;
int global_max_index = -1;

/**
 * Функция потока для вычисления потенциалов точек
 * Вычисляет потенциалы для точек в диапазоне [start, end)
 * Потенциал вычисляется по формуле: E a * exp(-b * r_ij)
 */
void compute_potentials(const vector<Point>& points, int start, int end, double a, double b) {
    double local_max = -1.0;
    int local_index = -1;

    for (int i = start; i < end; ++i) {
        double potential = 0.0;

        for (size_t j = 0; j < points.size(); ++j) {
            if (i == j) continue;
            double rij = distance(points[i], points[j]);
            potential += a * exp(-b * rij);
        }

        if (potential > local_max) {
            local_max = potential;
            local_index = i;
        }
    }

    lock_guard<mutex> lock(mtx_potential);
    if (local_max > global_max_potential) {
        global_max_potential = local_max;
        global_max_index = local_index;
    }
}

/**
 * Основная функция для задания 2
 * Находит точку с максимальным потенциалом в множестве
 */
void task2_potential(const vector<Point>& points, int num_threads, double a, double b) {
    cout << "\nЗАДАНИЕ 2: Поиск точки с максимальным потенциалом" << endl;
    cout << "Параметры: a = " << a << ", b = " << b << endl;

    global_max_potential = -1.0;
    global_max_index = -1;
    auto start = high_resolution_clock::now();

    vector<thread> threads;
    int chunk_size = points.size() / num_threads;

    // Создание и запуск потоков
    for (int t = 0; t < num_threads; ++t) {
        int start_idx = t * chunk_size;
        int end_idx = (t == num_threads - 1) ? points.size() : start_idx + chunk_size;
        threads.push_back(thread(compute_potentials, cref(points), start_idx, end_idx, a, b));
    }

    // Ожидание завершения потоков
    for (auto& th : threads) {
        th.join();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Точка с максимальным потенциалом: индекс = " << global_max_index
         << ", потенциал = " << global_max_potential << endl;
    cout << "Координаты: (" << points[global_max_index].x
         << ", " << points[global_max_index].y << ")" << endl;
    cout << "Время выполнения: " << duration.count() << " мс" << endl;
    cout << "Количество потоков: " << num_threads << endl;
}

// Основная функция программы
int main() {
    cout << "Многопоточные вычисления над множеством точек" << endl;


    // Параметры задачи
    const int N = 10000;
    const int num_threads = 4;
    const double a = 1.0;
    const double b = 1.0;

    // Генерация случайных точек
    cout << "\nГенерация " << N << " случайных точек..." << endl;
    vector<Point> points;
    srand(42);

    for (int i = 0; i < N; ++i) {
        points.push_back(Point(rand() % 1000, rand() % 1000));
    }
    cout << "Генерация завершена!" << endl;

    // Выполнение задания 1
    double diameter = task1_diameter(points, num_threads);

    // Выполнение задания 2
    task2_potential(points, num_threads, a, b);

    // Вывод сводки результатов
    cout << "\nСводка результатов:" << endl;
    cout << "Диаметр множества точек: " << diameter << endl;
    cout << "Точка с максимальным потенциалом:" << endl;
    cout << "  Индекс: " << global_max_index << endl;
    cout << "  Координаты: (" << points[global_max_index].x
         << ", " << points[global_max_index].y << ")" << endl;
    cout << "  Потенциал: " << global_max_potential << endl;

    return 0;
}