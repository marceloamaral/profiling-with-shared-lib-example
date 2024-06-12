#pragma once

#include <functional>

class LibPrint {
public:
  using Callback = std::function<void()>;

  static void printString(const char *str);
  static void registerEnterCallback(Callback callback);
  static void registerExitCallback(Callback callback);

private:
  static Callback enterCallback;
  static Callback exitCallback;
};
