1. Compile main with `g++ -ldl -lboost_system -lboost_filesystem -o main main.cpp foo.cpp`
2. Compile libhelloworld.so with `g++ -fPIC -shared -o libhelloworld.so helloworld.cpp`
3. Run with `./main`
