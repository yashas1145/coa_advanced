#pragma once

#include "iostream"
#include "omp.h"

using namespace std;

void greetSerial() {
	cout << "Hello World!! - Serial call\n";
}

void greetParallel(int n) {
	cout << "Hello world!! - Parallel call - Thread " << n << "\n";
}

double greetSerialWithTime() {
	int thread = omp_get_thread_num();
	double start = omp_get_wtime();
	cout << "Hello world as a serial call - Thread " << thread << "\n";
	double end = omp_get_wtime();

	cout << "Time of execution of thread" << ": " << end - start << " ms.\n";
	return end - start;
}

void greetParallelWithTime(int n) {
	double start = omp_get_wtime();
	cout << "Hello world from thread " << n << "\n";
	double end = omp_get_wtime();

	cout << "Time of execution of thread " << n << ": " << end - start << " ms.\n";
}
