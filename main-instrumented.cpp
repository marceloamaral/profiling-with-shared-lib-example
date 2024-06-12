#include "libprint.h"
#include "libprofiler.h"

int main() {
  LibProfiler::registerProfilingCallbacks();
  LibPrint::printString("Hello, World!");
  return 0;
}