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
    //реализация сортировки методом шейкера
    int l = 0, r = 1;
    for (int i = 0; i < n; i++) {
        for (int j = l; j < n-r; j++) {
            if (array[j] > array[j+1]) {
                int elem = array[j];
                array[j] = array[j+1];
                array[j+1] = elem;
            }
        }
        for (int j = n-r; j > l; j--) {
            if (array[j] < array[j-1]) {
                int elem = array[j];
                array[j] = array[j-1];
                array[j-1] = elem;
            }
        }
        l += 1;
        r += 1;
    }
    cout << "Отсортированный массив методом пузырька имеет вид: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }
    cout << '\n';
    return 0; 
} 
