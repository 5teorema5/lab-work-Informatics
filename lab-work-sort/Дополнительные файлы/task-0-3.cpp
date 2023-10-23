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
    //реализация сортировки методом вставки
    for (int i = 1; i < n; i++) {
        int j = i;
        while (array[j] < array[j-1] && j > 0)
        if (array[j] < array[j-1]) {
            int elem = array[j];
            array[j] = array[j-1];
            array[j-1] = elem;
            j -= 1;
        }
    }
    cout << "Отсортированный массив методом вставки имеет вид: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }
    cout << '\n';
    return 0;
}