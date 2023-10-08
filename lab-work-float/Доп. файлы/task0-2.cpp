#include <iostream>
using namespace std;

void Binary(unsigned int n) {
    for (int i = 0; i < 32; i++) {
        if (n == ((n << 1) >> 1)) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        n = n << 1;
    }
    cout << '\n';
}

int main() {
    unsigned int n;
    cin >> n;
    Binary(n);
    return 0;
}