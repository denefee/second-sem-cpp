#include <iostream>
#include <chrono>
#include <random>


int* generator(int N) {
    int* arr = new int[N];
    for (int i {0}; i < N; i++)
        arr[i] = i;

    return arr;
}


int hudsh_finder_poln(int N, int* arr) {
    for (int i {0}; i < N; i++) {
        if (arr[i] != -1) {
            continue;
        }
    }
    return 0;
}


int main() {
    int N = 1000000;
    int* arr = generator(N);
    for (int i = 100; i < 1000001; i += 100) {
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < 10; j++) {
            hudsh_finder_poln(i, arr);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>((end - begin)/10);
        std::cout << time_span.count() << std::endl;
    }
    delete arr;

    return 0;
}