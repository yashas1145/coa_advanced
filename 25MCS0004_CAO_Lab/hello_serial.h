#pragma once

#include "iostream"
#include "omp.h"

using namespace std;

void greetHelloAsSerial() {
	cout << "Hello - serial - Thread(" << omp_get_thread_num() << ")" << endl;
}