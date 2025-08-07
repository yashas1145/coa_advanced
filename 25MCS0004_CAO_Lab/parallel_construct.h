#pragma once

#include "iostream"
#include "omp.h"

using namespace std;

void ompLoopNormal(int num) {
	for (int i = 0; i < num; i++) {
		cout << i << " ";
	}
	cout << endl;
}

void ompLoopWithLoopConstruct(int num) {
	#pragma omp parallel for
	for (int i = 0; i < num; i++) {
		int threadNum = omp_get_thread_num();
		cout << i << ". Thread: "<< threadNum <<endl;
	}
}