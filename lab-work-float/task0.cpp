#include <iostream>
using namespace std;
        
void Binary_shift(unsigned int n) {
    int x[32] = {0};
    for (int i = 0; i < 32; i++) {
        x[i] = (n - ((n >> 1) << 1 ));
        n = n >> 1;
    }
    for (int i = 31; i >= 0; i--) {
        cout << x[i];
    }
    cout << '\n';
}
void Binary_division(unsigned int n) {
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
    int n;
    cin >> n;
    Binary_shift(n);
    cout << '\n';
    Binary_division(n);
    return 0;
}