#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int x = INT_MAX;
    float y = FLT_MAX;
    double z = DBL_MAX;
    printf("%d %d\n", x, (int) sizeof(x));
    printf("%f %d\n", y, (int) sizeof(y));
    printf("%f %d\n", z, (int) sizeof(z));
    return 0;
}
