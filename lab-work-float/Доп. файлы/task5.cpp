#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono> 

double get_time() { 
    return std::chrono::duration_cast<std::chrono::microseconds> 
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e3; 
};

using namespace std;

//формула Валлиса
void rad1 () {
    ofstream f("1-2.csv", ios::out);
    const double PI = 3.14159265359;
    int l = 1;
    float pi=1, t=2, time_0 = get_time();
    for (int i=1; i< 10001; i+=1) {
        pi *= (t*t)/((t-1)*(t+1));
        t += 2;
        for (int j = l; j < 11; j++) {
            if (round(2*pi*pow(10, j))/pow(10, j) == round(PI*pow(10, j))/pow(10, j)) {
                cout << i << " " << j << " " << abs(get_time()-time_0) << " ms" << '\n';
                f << j <<'\t'<< abs(get_time()-time_0) << endl;
                l ++;
                break;
            }
        }
    }
    cout << '\n';
};

//ряд Лейбница
void rad2 () {
    ofstream f("1-1.csv", ios::out);
    const double PI = 3.14159265359;
    int l = 1;
    float pi=0, t=1, time_0 = get_time();
    for (int i=1; i < 100000000; i+=1) {
        int k = -1;
        for (int j = 0; j < i; j++) {
            k = k * (-1);
        }
        pi += k / t;
        for (int j = l; j < 11; j++) {
            if (round(4*pi*pow(10, j))/pow(10, j) == round(PI*pow(10, j))/pow(10, j)) {
                cout << i << " " << j << " " << abs(get_time()-time_0) << " ms" << '\n';
                f << j <<'\t'<< abs(get_time()-time_0) << endl;
                l ++;
                break;
            }
        }
        t += 2;
    }
    cout << '\n';
};
//Франсуа Виет
void rad3 () {
    ofstream f("1-3.csv", ios::out);
    const double PI = 3.14159265359;
    int l = 1;
    float a = 0.0, pi = 1, time_0 = get_time();
    for (int i = 0; i < 1000001; i++) {
        a = sqrt(2 + a);
        pi = pi * a/2;
        for (int j = l; j < 11; j++) {
            if (round(2/pi*pow(10, j))/pow(10, j) == round(PI*pow(10, j))/pow(10, j)) {
                cout << i << " " << j << " " << abs(get_time()-time_0) << " ms" << '\n';
                f << j <<'\t'<< abs(get_time()-time_0) << endl;
                l ++;
                break;
            }
        }
    }
};
//Преобразование Мадхава
void rad4 () {
    ofstream f("1-4.csv", ios::out);
    const double PI = 3.14159265359;
    int l = 1;
    float pi  = 0, time_0 = get_time();
    for (int i = 0; i < 10000000000; i++) {
        pi += pow(-1, i)/(pow(3, i)*(2*i+1));
        for (int j = l; j < 11; j++) {
            if (round(2*sqrt(3)*pi*pow(10, j))/pow(10, j) == round(PI*pow(10, j))/pow(10, j)) {
                f << j <<'\t'<< abs(get_time()-time_0) << endl;
                cout << i << " " << j << " " << abs(get_time()-time_0) << " ms" << '\n';
                l ++;
                break;
            }
        }
    }
    cout << '\n';
};

int main() {

    rad4();

    cout << 0;
    return 0;
}