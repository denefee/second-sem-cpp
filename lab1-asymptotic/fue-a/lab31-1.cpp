#include <iostream>
#include <chrono>
#include <random>

/*стратегия а, изменится ли асимптотика, если значения равномерно распределены?*/


int random(int* arr) {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, 9);

    return arr[dstr(rng)];
}


int* generator(int N) {
    int* arr = new int[N];
    for (int i {0}; i < N; i++)
        arr[i] = i;

    return arr;
}


/*int* rand_arr(int N) {
    int* arr = new int[N];
    int* bas = generator(N);
    for (int i {0}; i < N; i++)
        std::cin >> random(bas) >> arr[i];

    return arr;
}*/


int strategy_a(int*& arr, int N, int x) {
    for (int i = 0; i < N; i++) {
        if ((arr[i] == x) && (i != 0)) {
            int zam = arr[0];
            arr[i] = zam;
            arr[0] = x;
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}


int main() {
    int N = 2000;
    int* bas = generator(N + 1);
    for (int i = 10; i < N + 1; i += 10) {    
        int* arr = generator(i);
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < 75; j++) {
            for (int k = 0; k <= i + 1; k++) {
                strategy_a(arr, i, bas[k]);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/(75));
        std::cout << time_span.count() << std::endl;
        delete arr;
    }
    delete bas;

    return 0;
}