#include <iostream>
using namespace std;

#include <xmmintrin.h>     
/* enable DAZ (denormals are zero) and FTZ (flush to zero) */     
_mm_setcsr(_mm_getcsr() | 0x8040);     
/* disable DAZ and FTZ */     
_mm_setcsr(_mm_getcsr() & ~0x8040); 

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