#pragma once

#include "iostream"
#include "omp.h"

using namespace std;

void greetHelloAsParallel(int coreCount) {
	omp_set_num_threads(coreCount);

	#pragma omp parallel
	{
		int threadNumber = omp_get_thread_num();
		cout << "Hello - parallel - Thread("<< threadNumber << ")" << endl;
	}
}