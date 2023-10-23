#include <iostream>
using namespace std;

int main() { 
    int n, array[100] = {0};
    cout << "Введите длину массива:" << '\n';
    cin >> n;
    cout << "Вводите элементы массива через пробел: " << '\n';
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    //реализация сортировки методом выбора
    for (int i = 0; i < n; i++) {
        int min_elem = 10000, min_index;
        for (int j = i; j < n; j++) {
            if (array[j] < min_elem) {
                min_elem = array[j];
                min_index = j;
            }
        }
        array[min_index] = array[i];
        array[i] = min_elem;
    }
    cout << "Отсортированный массив методом выбора имеет вид: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }
    cout << '\n';
    return 0; 
} 
