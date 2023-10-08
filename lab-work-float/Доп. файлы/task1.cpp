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

union FloatNumbers{
    float f;
    unsigned int u;
};

int main() {
    FloatNumbers number;
    cin >> number.f;
    Binary(number.u);
    return 0;
}