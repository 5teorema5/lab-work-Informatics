#include <iostream>

using namespace std;

void Binary(unsigned int n) {
    int x[32] = {0};
    for (int i = 0; i < 32; i++) {
        x[i] = (n - ((n >> 1) << 1 ));
        n = n >> 1;
    }
    for (int i = 31; i > 0; i--) {
        cout << x[i];
    }
    cout << '\n';
}

union fu{
    float f;
    unsigned int u;
};

int main() {
    float big = 1.0;
    cout << fixed;
    cout.precision(2);
    fu a;
    for (int i = 0; i < 100; i++) {
        a.f = big;
        cout << a.f << '\n';
        Binary(a.u);
        big *= 10.0;
    }
    return 0;
}