#include <stdio.h>

//we are finding all possible one then negating it
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    printf("bitAnd(6, 5) = %d\n", bitAnd(6, 5));
    printf("bitAnd(12, 10) = %d\n", bitAnd(12, 10));
    return 0;
}
