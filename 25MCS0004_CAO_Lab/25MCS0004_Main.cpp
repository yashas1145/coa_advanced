//#include "iostream"
//#include "omp.h"
//
//#include "Greet.h"
//
//int main() {
//	omp_set_num_threads(2);
//
//	//greetSerial();
//
//	/*#pragma omp parallel
//	{
//		int threadId = omp_get_thread_num();
//		greetParallel(threadId);
//	}*/
//
//	double execTimeOfSerial = greetSerialWithTime();
//
//	double start = omp_get_wtime();
//	#pragma omp parallel
//	{
//		int thread = omp_get_thread_num();
//		greetParallelWithTime(thread);
//	}
//	double end = omp_get_wtime();
//	cout << "Time for parallel processing: " << end - start << " ms.\n";
//
//	//Exec time of serial proc. by Exec time of parallel proc.
//	double speedUp = execTimeOfSerial / (end - start);
//	//SpeedUp * Number of Processors / 100
//	double efficiency = speedUp / 0.02;
//
//	cout << "Speed Up: " << speedUp << "\n";
//	cout << "Efficiency: " << efficiency << " %\n";
//
//	int choice = 0;
//
//	while (true) {
//		
//	}
//
//	return 0;
//}
