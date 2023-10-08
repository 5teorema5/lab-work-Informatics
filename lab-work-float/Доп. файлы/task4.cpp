#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

//формула Валлиса
void rad1 () {
    ofstream f("1.csv", ios::out);
    float pi=1, t=2;
    for (int i=1; i< 10001; i+=10) {
        pi *= (t*t)/((t-1)*(t+1));
        t += 2;
        f << i<<'\t'<<pi*2 << endl;
    }
    cout << '\n';
};
//ряд Лейбница
void rad2 () {
    ofstream f("2.csv", ios::out);
    float pi=0, t=1;
    for (int i=1; i < 101; i+=1) {
        int k = -1;
        for (int j = 0; j < i; j++) {
            k = k * (-1);
        }
        pi += k / t;
        f << i<<'\t'<<pi*4 << endl;
        t += 2;
    }
    cout << '\n';
};
//Франсуа Виет
void rad3 () {
    ofstream f("3.csv", ios::out);
    float a = 0.0, pi = 1;
    for (int i = 0; i < 101; i++) {
        a = sqrt(2 + a);
        pi = pi * a/2;
        f << i<<'\t'<<2/pi << endl;
    }
};
//Преобразование Мадхава
void rad4 () {
    ofstream f("4.csv", ios::out);
    float pi  = 0;
    for (int i = 0; i < 10000000000; i++) {
        pi += pow(-1, i)/(pow(3, i)*(2*i+1));
        f << i<<'\t'<<2*sqrt(3)*pi << endl;
    }
    cout << '\n';
};

int main() {
    //формула Валлиса
    rad1();
    //ряд Лейбница
    rad2();
    //Франсуа Виет
    rad3();
    //Преобразование Мадхава
    rad4();
    cout << 0;
    return 0;
}