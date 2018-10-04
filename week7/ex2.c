#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *p;
    scanf("%d", &N);
    p = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        *(p + i) = i;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", *(p + i));
    }

    free(p);
    return 0;
}
