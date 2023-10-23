#include <iostream>
#include <random>
#include <chrono>
using namespace std;

//реализация сортировки методом Хоара 
void hoarasort(int* array, int first, int last) {
    int i = first, j = last;
    int p, opora = array[(first + last) / 2];
    do {
        while (array[i] < opora) {
            i++;
        }
        while (array[j] > opora) {
            j--;
        }
        if (i <= j) {
            if (i < j) {
                p = array[i];
                array[i] = array[j];
                array[j] = p;
            }
            i++;
            j--;
        }
    } while (i <= j);
    
    if (i < last)
    hoarasort(array, i, last);
    if (first < j)
    hoarasort(array, first,j);
}

int main() { 
    int n, array[100] = {0}, sortArray[100] = {0};
    cout << "Введите длину массива:" << '\n';
    cin >> n;
    cout << "Вводите элементы массива через пробел: " << '\n';
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    hoarasort(array, 0, n-1);
        for (int i = 0; i < n; i++) {
            sortArray[i] = array[n-1-i];
        }
    cout << "Отсортированный массив методом пузырька имеет вид: ";
    for (int i = 0; i < n; i++) {
        cout << sortArray[i] << ' ';
    }
    cout << '\n';
    return 0; 
} 
