//#include "iostream"
//
//#include "parallel_construct.h"
//
//using namespace std;
//
//int main() {
//	int numCores;
//
//	cout << "Enter number of cores (1-4): ";
//	cin >> numCores;
//
//	cout << "Functioning with " << numCores << " cores" << endl;
//
//	omp_set_num_threads(numCores);
//	while (true) {
//		int choice;
//
//		cout << "1.Simple FOR 2.OMP FOR 3.Exit: ";
//		cin >> choice;
//
//		switch (choice) {
//			case 1: {
//				int num;
//				
//				cout << "Enter number of iterations: ";
//				cin >> num;
//
//				ompLoopNormal(num);
//				break;
//			}
//			case 2: {
//				int num;
//
//				cout << "Enter number of iterations: ";
//				cin >> num;
//
//				ompLoopWithLoopConstruct(num);
//				break;
//			}
//			case 3: {
//				cout << "Bye!" << endl;
//				exit(0);
//			}
//			default: cout << "Invalid choice!" << endl;
//		}
//	}
//	return 1;
//}