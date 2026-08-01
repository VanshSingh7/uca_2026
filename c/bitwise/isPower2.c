#include <stdio.h>

int isPower2(int x) {
    return !(x & (x + ~0)) & !!x & !(x >> 31);
}

int main() {
    printf("isPower2(8) = %d\n", isPower2(8));
    printf("isPower2(5) = %d\n", isPower2(5));
    return 0;
}
