#include <stdio.h>
#include <stdlib.h>

const int NF = 10,NB = 31, EV = -1, RE = 1;


int main()
{
    int p[NF],a[NF];
	FILE* fp = fopen("9.txt", "r");
	int i;
	for (i = 0; i < NF; i++)
		p[i] = EV;
	i = 0;
	int t = 0, MissNumber = 0, j;

	while (fscanf(fp, "%d", &j) == RE) {
		int Fault = 1;
		int Elder = 0;

		for (i = 0; i < NF; i++) {
			if (p[i] == j) {
				a[i] = (1 << (NB - 1)) & (a[i] >> 1);
				Fault = 0;
			} else {
				a[i] = a[i] >> 1;
			}
			if (a[i] < a[Elder] || p[i] == EV)
				Elder = i;
		}

		++t;
		if (!Fault) continue;
		++MissNumber;
		a[Elder] = 1 << (NB - 1);
		p[Elder] = j;
	}


	printf("frames => %d\n in total => %d\n #hits => %d\n #misses => %d\n", NF, t, t - MissNumber, MissNumber);
	printf("hits/miss => %.2f\n", (double)(t-MissNumber)/(MissNumber));

	return 0;
}
