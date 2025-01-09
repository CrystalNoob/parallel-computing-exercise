#include <omp.h>
#include <stdio.h>
#define ll long long

static double steps = 1e10;

int main() {
	int threads = omp_get_max_threads();
	double pi = 0.0, step = (1 / steps);

#pragma omp parallel
	{
		int id = omp_get_thread_num();
		double sum;
		for (ll i = id; i < steps; i += threads) {
			double x = i * step;
			sum += 4.0 / (1.0 + x * x);
		}
#pragma omp critical
		pi += step * sum;

		printf("%d %lf\n", omp_get_thread_num(), sum);
	}

	printf("%lf", pi);
}
