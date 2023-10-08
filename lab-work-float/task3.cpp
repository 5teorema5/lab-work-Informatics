#include <iostream>
using namespace std;

int main() {
    for (float i = 0; i <= 100000000; i++) {
        if (i+1 == i) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}