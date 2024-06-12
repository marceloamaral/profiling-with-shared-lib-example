#pragma once

#include <cstdlib>
#include <iostream>

class LibProfiler {
public:
  LibProfiler() {
    const char *enableProfiling = std::getenv("ENABLE_PROFILING");
    if (enableProfiling) {
      registerProfilingCallbacks();
    }
  }
  static void registerProfilingCallbacks();

private:
  static void enterCallback();
  static void exitCallback();
  static std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

LibProfiler libProfilerInstance; // Create an instance on library load
