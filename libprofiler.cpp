#include "libprofiler.h"
#include "libprint.h"
#include <chrono>
#include <iostream>

// Define the static member variable
std::chrono::time_point<std::chrono::high_resolution_clock>
    LibProfiler::startTime;

void LibProfiler::enterCallback() {
  startTime = std::chrono::high_resolution_clock::now();
}

void LibProfiler::exitCallback() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime)
          .count();
  std::cout << "Function execution time: " << duration << " microseconds"
            << std::endl;
}

void LibProfiler::registerProfilingCallbacks() {
  std::cout << "Init profiling" << std::endl;
  LibPrint::registerEnterCallback(enterCallback);
  LibPrint::registerExitCallback(exitCallback);
}