#include <iostream>
#include <chrono>
#include <random>

/*стратегия b, изменится ли асимптотика, если значения неравномерно распределены?*/

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


int strategy_b(int*& arr, int N, int x) {
    for (int i = 0; i < N; i++) {
        if ((arr[i] == x) && (i != 0)) {
            int zam = arr[i - 1];
            arr[i - 1] = x;
            arr[i] = zam;
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}


int main() {
    int N = 100000;
    int* bas = new int[5];
    for (int i = 100; i < 100001; i += 100) {    
        int* arr = generator(i);
            bas[0] = 0;
            bas[1] = floor(i/4);
            bas[2] = floor(i/2);
            bas[3] = floor(3*i/4);
            bas[4] = i - 1;
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < 200; j++) {
            for (int k = 0; k < 5; k++) {
                strategy_b(arr, i, bas[k]);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/200);
        std::cout << time_span.count() << std::endl;
        delete arr;
    }
    delete bas;

    return 0;
}