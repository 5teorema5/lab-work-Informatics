#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
using namespace std;

//реализация сортировки методом расчёстки 
void ras(int* array, int n) {
    // оптимальное число для вычисления шага сравнения
    const float factor = 1.247;
    // получаем точный шаг сравнения
    float gapFactor = n / factor;
    // пока шаг больше единицы
    while (gapFactor > 1) {
        // округляем шаг до целого
        const int gap = gapFactor;
        // и организуем цикл как в пузырьковой сортировке
        for (int i = 0, j = gap; j < n; i++, j++) {
            // если сначала идёт большое число
            if (array[i] > array[j]) {
                // меняем их местами
                int p = array[i];
                array[i] = array[j];
                array[j] = p;
            }
        }
        // в конце цикла рассчитываем новый шаг
        gapFactor = gapFactor / factor;
    }
}

int main() { 
    int n, array[100] = {0};
    cout << "Введите длину массива:" << '\n';
    cin >> n;
    cout << "Вводите элементы массива через пробел: " << '\n';
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    ras(array, n);
    cout << "Отсортированный массив методом пузырька имеет вид: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }
    cout << '\n';
    return 0; 
} 