# C++ Shared Libraries with Callback and Profiling Example

## Overview

This project demonstrates how to create and use two shared libraries in C++:
1. `libprint` - A library that provides a function to print a string and an API to register callbacks that are triggered on function entry and exit.
2. `libprofiler` - A library that registers callbacks to record timestamps and profile the execution time of the function provided by `libprint`.

The project also includes an application that uses these libraries to print a string and profile the function execution time.


## Build Instructions

1. Ensure you have a C++ compiler (e.g., `g++`) installed on your system.
2. Open a terminal and navigate to the directory containing the project files.
3. Run the following command to build the shared libraries and the application:
```sh
make
```

## Run Instructions

To build and run the application with the code instrumented to start the profiling:
 ```sh
make run-instrumented
```
You should see the printed string and the profiling output indicating the function's execution time.

To build and run the application with the code not instrumented:
 ```sh
make run-not-instrumented
```

To build and run the application with the code not instrumented but externally starting the profiling using `LD_PRELOAD=./libprofiler.so` and `ENABLE_PROFILING=1`:
 ```sh
make run-ld-preload
```


## Explanation

#### libprint Library
- `printString(const char* str)`: Prints the given string.
- `registerEnterCallback(Callback callback)`: Registers a callback function to be called on function entry.
- `registerExitCallback(Callback callback)`: Registers a callback function to be called on function exit.

#### libprofiler Library
- `registerProfilingCallbacks()`: Registers the enter and exit callbacks to record timestamps and profile the execution time of the `printString` function.

## License
This project is licensed under the MIT License.