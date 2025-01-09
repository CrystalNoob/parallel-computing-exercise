#include <omp.h>
#include <stdio.h>
#define ll long long

static double steps = 1e5;

int main() {
	int threads = omp_get_max_threads();
	double pi = 0.0, sum[threads], step = (1 / steps);

#pragma omp parallel
	{
		int id = omp_get_thread_num();
		for (ll i = id; i < steps; i += threads) {
			double x = i * step;
			sum[id] += 4.0 / (1.0 + x * x);
			// printf("%lld\n", i);
			// printf("%lf\n", x);
		}
		printf("%d %lf\n", omp_get_thread_num(), sum[id]);
	}

	for (int i = 0; i < threads; i++) {
		pi += step * sum[i];
	}

	printf("%lf", pi);
}
