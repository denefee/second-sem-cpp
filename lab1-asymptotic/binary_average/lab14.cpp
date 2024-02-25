#include <iostream>
#include <chrono>
#include <random>



/*int random(int* arr, int N) {
    unsigned seed = 1351;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, N);

    return arr[dstr(rng)];
}*/


int random(int min, int max) {
    srand(time(NULL)); // генератор случайных чисел
    int num = min + rand() % (max - min + 1); // получение случайного числа

    return num;
}


int* generator(int N) {
    int* arr = new int[N];
    for (int i {0}; i < N; i++)
        arr[i] = i;

    return arr;
}


int finder_bin(int* begin, int* end, int& x) {
    int* l = begin - 1;
    int* r = end;
    while (l < r - 1) {
        int* m = l + (r - l) / 2;
        if (!(*m < x) && !(x < *m)) {
            return *m;
        }
        if (*m < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return -1;
}
    

int main() { 
    for (int i = 1000; i < 1000000; i += 1000) {
        int* arr = generator(i); 
        auto begin = std::chrono::steady_clock::now();
        for (int j = 1; j < 20001; j++) {
            int x;
            x = random(0, i);
            finder_bin(arr, arr + i - 1, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/20000);
        std::cout << time_span.count() << std::endl;
        delete arr;
    }

    return 0;
}