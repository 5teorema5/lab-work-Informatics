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

void sort_p (int* array, int n) {
    int r = 1;
    ofstream f("1-1.csv", ios::app);
    int time_0 = get_time();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-r; j++) {
            if (array[j] > array[j+1]) {
                int elem = array[j];
                array[j] = array[j+1];
                array[j+1] = elem;
            }
        }
        r += 1;
    }
    f << n <<'\t'<< abs(get_time()-time_0) << endl;
};

void sort_v (int* array, int n) {
    int r = 1;
    ofstream g("1-2.csv", ios::app);
    int time_0 = get_time();
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
    g << n <<'\t'<< abs(get_time()-time_0) << endl;
};

void sort_vst (int* array, int n) {
    int r = 1;
    ofstream h("1-3.csv", ios::app);
    int time_0 = get_time();
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
    h << n <<'\t'<< abs(get_time()-time_0) << endl;
};

void sort_sh (int* array, int n) {
    ofstream t("1-4.csv", ios::app);
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
    t << n <<'\t'<< abs(get_time()-time_0) << endl;
};

int main() { 
    ofstream f("1-1.csv", ios::out);
    ofstream g("1-2.csv", ios::out);
    ofstream h("1-3.csv", ios::out);
    ofstream t("1-4.csv", ios::out);
    int array[100000] = {0};
    for (int n = 1; n < 100000; n+=1000) {
        for (int i = 0; i < n; i++) {
            array[i] = rand_uns(-1000, 1000);
        }
        sort_p (array, n);
        sort_v (array, n);
        sort_vst (array, n);
        sort_sh (array, n);
    }
    cout << '\n';
    return 0; 
} 
