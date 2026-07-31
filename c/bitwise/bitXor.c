#include <stdio.h>
 
int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}

int main() {
    printf("bitXor(4, 5) = %d\n", bitXor(4, 5));
    printf("bitXor(10, 3) = %d\n", bitXor(10, 3));
    return 0;
}
