#include <iostream>
#include <chrono>
#include <fstream>
#include <random> 
using namespace std;

int rand_uns(int min, int max) { 
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
    static std::default_random_engine e(seed); 
    std::uniform_int_distribution<int> d(min, max); 
    return d(e); 
}

double get_time() { 
    return chrono::duration_cast<chrono::microseconds> 
        (chrono::steady_clock::now().time_since_epoch()).count()/1e3; 
}

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
    ofstream f("sort-o1-ras.csv", ios::out);
    int array[500000] = {0};
    for (float n = 1; n < 50000; n+=1000) {
        ofstream f("sort-o1-ras.csv", ios::app);
        for (int i = 0; i < n; i++) {
            array[i] = rand_uns(-1000, 1000);
        }
        int time_0 = get_time();
        ras(array,n);
        f << n <<'\t'<< abs(get_time()-time_0) << endl;
    }
    cout << '\n';
    return 0; 
} 
