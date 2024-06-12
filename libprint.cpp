#include "libprint.h"
#include <iostream>

// Define static member variables
LibPrint::Callback LibPrint::enterCallback = nullptr;
LibPrint::Callback LibPrint::exitCallback = nullptr;

void LibPrint::printString(const char *str) {
  if (enterCallback)
    enterCallback();
  std::cout << str << std::endl;
  if (exitCallback)
    exitCallback();
}

void LibPrint::registerEnterCallback(Callback callback) {
  enterCallback = callback;
}

void LibPrint::registerExitCallback(Callback callback) {
  exitCallback = callback;
}
