//#include "iostream"
//#include "omp.h"
//
//#include "rer_metrics.h"
//
//using namespace std;
//
//int main() {
//	double startTime, endTime;
//	double serialTime = 0, parallelTime = 0;
//	int coreCount;
//
//	cout << "Total core count: " << omp_get_max_threads() << endl;
//
//	cout << "Enter desired number of cores (0-4): ";
//	cin >> coreCount;
//
//	startTime = omp_get_wtime();
//	cout << "Hello - from main" << endl;
//	endTime = omp_get_wtime();
//
//	cout << "Main function greeted hello in " << (endTime - startTime) << " ms." << endl << endl;
//	
//	int choice = 0;
//
//	while (true) {
//		cout << "1.Serial greet 2.Parallel greet 3.Serial metric 4.Parallel metric 5.CPU metric 6.Exit: ";
//		cin >> choice;
//		switch (choice) {
//			case 1: {
//				greetHelloAsSerial();
//				break;
//			}
//			case 2: {
//				greetHelloAsParallel(coreCount);
//				break;
//			}
//			case 3: {
//				serialTime = serialGreetMetric();
//				break;
//			}
//			case 4: {
//				parallelTime = parallelGreetMetric(coreCount);
//				break;
//			}
//			case 5: {
//				if (serialTime == 0 || parallelTime == 0) {
//					cout << "Run the serial and parallel metrics at least once!" << endl;
//					break;
//				}
//				printCpuMetrics(coreCount, serialTime, parallelTime);
//				break;
//			}
//			case 6: {
//				cout << "Bye!" << endl;
//				exit(0);
//			}
//			default: cout << "Invalid choice!" << endl;
//		}
//	}
//	return 0;
//}