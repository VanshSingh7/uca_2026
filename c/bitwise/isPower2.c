#include <stdio.h>

int isPower2(int x) {
    return !(x & (x + ~0)) & !!x & !(x >> 31);
}

int main() {
    printf("isPower2(24) = %d\n", isPower2(24));
    printf("isPower2(1024) = %d\n", isPower2(1024));
    return 0;
}
