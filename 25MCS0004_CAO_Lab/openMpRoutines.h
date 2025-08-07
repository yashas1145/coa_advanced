#pragma once

#include "iostream"
#include "omp.h"

void demonstrate_omp_api() {
    std::cout << "===== OpenMP Demo =====\n";

    // Set up threads and OpenMP environment
    omp_set_num_threads(4);
    omp_set_dynamic(0);
    omp_set_nested(1);

    std::cout << "Set number of threads to 4\n";
    std::cout << "Dynamic threads disabled\n";
    std::cout << "Nested parallelism enabled\n";

    std::cout << "omp_get_num_procs(): " << omp_get_num_procs() << "\n";
    std::cout << "omp_get_dynamic(): " << omp_get_dynamic() << "\n";
    std::cout << "omp_get_nested(): " << omp_get_nested() << "\n";

    // Setup lock
    omp_lock_t lock;
    omp_init_lock(&lock);

    // Setup nested lock
    omp_nest_lock_t nest_lock;
    omp_init_nest_lock(&nest_lock);

    double start_time = omp_get_wtime();

#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        // Each thread tries to acquire a lock
        if (omp_test_lock(&lock)) {
#pragma omp critical
            std::cout << "Thread " << tid << " acquired the simple lock\n";

            omp_unset_lock(&lock);
        }

        // Nested lock region
        omp_set_nest_lock(&nest_lock);
#pragma omp critical
        {
            std::cout << "Thread " << tid << " entered nested lock region\n";
            std::cout << "  Total threads: " << nthreads << "\n";
            std::cout << "  omp_in_parallel(): " << omp_in_parallel() << "\n";
        }
        omp_unset_nest_lock(&nest_lock);
    }

    double end_time = omp_get_wtime();

    // Cleanup
    omp_destroy_lock(&lock);
    omp_destroy_nest_lock(&nest_lock);

    std::cout << "\n===== Timing Info =====\n";
    std::cout << "Elapsed time: " << (end_time - start_time) << " seconds\n";
    std::cout << "Timer precision (omp_get_wtick()): " << omp_get_wtick() << " seconds\n";
}
