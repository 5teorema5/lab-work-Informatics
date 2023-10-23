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
};

void sort (int* array, int n) {
    ofstream f("sort-o1-sh.csv", ios::app);
    int time_0 = get_time();
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
    f << n <<'\t'<< abs(get_time()-time_0) << endl;
};

int main() { 
    ofstream f("sort-o1-sh.csv", ios::out);
    int array[100000] = {0};
    for (float n = 1; n < 50000; n+=1000) {
        for (int i = 0; i < n; i++) {
            array[i] = rand_uns(-1000, 1000);
        }
        sort (array, n);
    }
    cout << '\n';
    return 0; 
} 