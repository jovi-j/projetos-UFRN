#include <stdio.h>

int main() {
	int hours = 0, n, hh = 0;
	float max = 0.0, min = 0.0, highDiff = 0.0;
	scanf("%d", &n);
	if (n == 0) { return 0; }
	for (int i = 0; i < n; i++) {
		scanf("%i %f %f ", &hours, &max, &min);
		float diff = max - min;
		if (highDiff < diff) {
			highDiff = diff;
			hh = hours;
		}
	}

	printf("%d\n", hh);
	return 0;
}
