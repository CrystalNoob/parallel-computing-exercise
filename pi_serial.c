#include <stdio.h>
#define ll long long

static double num_steps = 1e5;

int main() {
	double x, pi, sum = 0.0, step = 1.0 / num_steps;
	for (ll i = 0; i < num_steps; i++) {
		x = i * step;
		sum += 4.0 / (1.0 + x * x);
	}
	pi = step * sum;
	printf("%lf", pi);
}
