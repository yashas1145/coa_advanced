#pragma once

#include "iostream"
#include "omp.h"

#include "hello_serial.h"
#include "hello_parallel.h"

using namespace std;

double serialGreetMetric() {
	double start, end;
	start = omp_get_wtime();
	greetHelloAsSerial();
	end = omp_get_wtime();

	return end - start;
}

double parallelGreetMetric(int coreCount) {
	double start, end;
	start = omp_get_wtime();
	greetHelloAsParallel(coreCount);
	end = omp_get_wtime();

	return end - start;
}

void printCpuMetrics(int coreCount, double serialTime, double parallelTime) {
	cout << "Current execution being done with " << coreCount << " cores." << endl;
	cout << "Serial execution took " << serialTime << " ms." << endl;
	cout << "Parallel execution took " << parallelTime << " ms." << endl;

	double speedUp = serialTime / parallelTime;
	double efficiency = speedUp / coreCount * 100;

	cout << "Speed up factor = " << speedUp << endl;
	cout << "Efficiency = " << efficiency << " %" << endl;
}