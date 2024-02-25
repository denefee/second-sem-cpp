#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h> 


int random(int* arr, int N) {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, N);

    return arr[dstr(rng)];
}


int* generator(int N) {
    int* arr = new int[N];
    for (int i {0}; i < N; i++)
        arr[i] = i;

    return arr;
}


int finder_poln(int* arr, int N, int x) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}


/*
int timer() {
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0 ; --cnt)
        func();
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "\n\n";
    std::cout << time_span.count ( ) << std::endl;
}
*/

 
int main() {

    for (int i = 1000; i < 1000000; i += 1000) {
        int* arr = generator(i);
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < 2000; j++) {
            int x;
            x = random(arr, i);
            finder_poln(arr, i, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/2000);
        std::cout << time_span.count() << std::endl;
        delete arr;
    }

    return 0;
}