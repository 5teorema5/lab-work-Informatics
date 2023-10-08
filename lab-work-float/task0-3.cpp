#include <iostream>
using namespace std;

void Binary(unsigned int n) {
    int x[32] = {0};
    for (int i = 31; i >= 0; i--) {
        x[i] = n%2;
        n /= 2;
    }
    for (int i = 0; i < 32; i++) {
        cout << x[i];
    }
    cout << '\n';
}

int main() {
    unsigned int n;
    cin >> n;
    Binary(n);
    return 0;
}