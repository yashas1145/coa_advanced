#pragma once
#define MAX 10

#include "iostream"

#include "omp.h"

using namespace std;

void init(int arr[]) {
	for (int i = 0; i < MAX; i++)
		arr[i] = i + 1;
}

void computeSquares(int arr[], int square[]) {
	for (int i = 0; i < MAX; i++) {
		cout << "T" << omp_get_thread_num() << ": Square of " << arr[i] << " = " << arr[i] * arr[i] << endl;
		square[i] = arr[i] * arr[i];
	}
}

void computeSquaresParallel(int arr[], int square[]) {
	#pragma omp parallel for
	for (int i = 0; i < MAX; i++) {
		cout << "T" << omp_get_thread_num() << ": Square of " << arr[i] << " = " << arr[i] * arr[i] << endl;
		square[i] = arr[i] * arr[i];
	}
}

void display(int square[]) {
	//cout << "**************************************" << endl;
	for (int i = 0; i < MAX; i++)
		cout << square[i] << " ";

	cout << endl;
	//cout << "**************************************" << endl;
}

void driver() {
	int arr[MAX] = { 0 }, squares[MAX] = { 0 };

	init(arr);

	double serialStart, serialEnd;
	serialStart = omp_get_wtime();
	computeSquares(arr, squares);
	serialEnd = omp_get_wtime();
	
	double parallelStart, parallelEnd;
	parallelStart = omp_get_wtime();
	computeSquaresParallel(arr, squares);
	parallelEnd = omp_get_wtime();

	//display(squares);
	double efficiency, speedup;

	speedup = (serialEnd - serialStart) / (parallelEnd - parallelStart);
	efficiency = speedup / 2 * 100;

	cout << "Serial execution time: " << (serialEnd - serialStart) << " ms" << endl;
	cout << "Parallel execution time: " << (parallelEnd - parallelStart) << " ms" << endl;
	cout << "Speed up: " << speedup << endl;
	cout << "Efficiency: " << efficiency << "%" << endl;
}