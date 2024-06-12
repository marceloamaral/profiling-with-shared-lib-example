CXX = g++
CXXFLAGS = -std=c++11 -fPIC -shared

all: libprint.so libprofiler.so main-not-instrumented

libprint.so: libprint.cpp libprint.h
	$(CXX) $(CXXFLAGS) -o libprint.so libprint.cpp

libprofiler.so: libprofiler.cpp libprofiler.h libprint.h
	$(CXX) $(CXXFLAGS) -o libprofiler.so libprofiler.cpp -L. -lprint

main-not-instrumented: main-not-instrumented.cpp libprint.so libprofiler.so
	$(CXX) -o main-not-instrumented main-not-instrumented.cpp -L. -lprint -lprofiler -std=c++11

main-instrumented: main-instrumented.cpp libprint.so libprofiler.so
	$(CXX) -o main-instrumented main-instrumented.cpp -L. -lprint -lprofiler -std=c++11

clean:
	rm -f *.o *.so main-instrumented main-not-instrumented

run-instrumented: clean main-instrumented
	./main-instrumented

run-not-instrumented: clean main-not-instrumented
	./main-not-instrumented

run-ld-preload: clean main-not-instrumented
	ENABLE_PROFILING=1 LD_PRELOAD=./libprofiler.so ./main-not-instrumented