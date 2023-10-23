#include <iostream>
using namespace std;

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int* array, int n, int i)
{
    int largest = i;   
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && array[l] > array[largest])
        largest = l;

   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && array[r] > array[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(array[i], array[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(array, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int array[], int n)
{
  // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(array[0], array[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(array, i, 0);
    }
}

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int* array, int n)
{
    for (int i=0; i<n; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

int main() { 
    int n, array[100] = {0};
    cout << "Введите длину массива:" << '\n';
    cin >> n;
    cout << "Вводите элементы массива через пробел: " << '\n';
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    heapSort(array, n);
    cout << "Отсортированный массив методом пузырька имеет вид: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }
    cout << '\n';
    return 0; 
} 