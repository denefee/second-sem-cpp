#include <iostream>
#include <chrono>
#include <random>
#include <math.h>


int* generator(int N) {
    int* arr = new int[N];
    for (int i {0}; i < N; i++)
        arr[i] = i;

    return arr;
}


int random(int N) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, N-1);

    return dist(rng);
}


int* rand_gen(int N) {
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        int x = random(N);
        arr[i] = x;
    }

    return arr;
}


int fib_count(int N) {
    int a = 1;
    int b = 2;
    int count = 1;
    while (b < N-1) {
        int temp = b;
        b = b + a;
        a = temp;
        count++;
    }

    return count;
}


void fib(int fibbo[], int N) {
    int a = 1;
    int b = 2;
    int i = 1;
    fibbo[0] = b;
    while (b < N-1) {
        int temp = b;
        b = b + a;
        a = temp;
        fibbo[i] = b;
        i++;
    }
}


void step(int arr[], int N, int step) {
    for (int i = step; i < N; i += step) {
        int key = arr[i];
        int j = i - step;
        while ((j >= 0)&&(arr[j] > key)) {
            arr[j + step] = arr[j];
            j -= step;
        }
        arr[j + step] = key;
    }
}


void shell_sort(int arr[], int N) {
    int fib_num = fib_count(N) - 1;
    int fibbo[fib_num];
    fib(fibbo, N);
    for (int i = fib_num - 1; i >= 0; i--) {
        int g = fibbo[i];
        step(arr, N, g);
    }
    
    bool sorted = false;
    while (sorted == false) {
        for (int i = 0; i < N-1; i++) {
            if (arr[i] > arr[i+1]) {
                sorted = false;
                step(arr, N, 1);
                break;
            }
            else {
                sorted = true;
            }
        }
    }
}


int main() {
    for (int N = 100; N < 10000; N += 100) {
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < 40; j++) {
            int* arr = rand_gen(N); 

            /*std::cout << "Array before sorting:" << std::endl;
            for (int p = 0; p < N; p++) {
                std::cout << arr[p] << " ";
            }
            std::cout << std::endl;*/

            shell_sort(arr, N);

            /*std::cout << "Array after sorting:" << std::endl;
            for (int p = 0; p < N; p++) {
                std::cout << arr[p] << " ";
            }
            std::cout << std::endl;*/

            delete arr;
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/40);
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}


/*  
std::cout << "Array before/after sorting:" << std::endl;
for (int p = 0; p < N; p++) {
    std::cout << arr[p] << " ";
}
std::cout << std::endl;


*/