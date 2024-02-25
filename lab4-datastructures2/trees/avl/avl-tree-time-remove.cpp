#include <iostream>
#include <chrono>
#include "AVL-set.h"
#include <random>
#include <fstream>

int main() {
    std::ofstream file1("remove-rand.txt");
    std::ofstream file2("remove-sort.txt");

    Set new_set1 = set_new();
    Set &set1 = new_set1;

    Set new_set2 = set_new();
    Set &set2 = new_set2;

    for (int i = 0; i < 100000; i++) {
        set_insert(set1, i);
        set_insert(set1, i+1);
        int seed = 1003;
        std::default_random_engine rnd(seed);
        std::uniform_int_distribution<int> dstr(0, i+1);

        auto begin1 = std::chrono::steady_clock::now();
        set_remove(set1, dstr(rnd));
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
        file1 << time_span1.count() << '\n';

        set_insert(set2, i);
        set_insert(set2, i+1);
        auto begin2 = std::chrono::steady_clock::now();
        set_remove(set2, i+1);
        auto end2 = std::chrono::steady_clock::now();
        auto time_span2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
        file2 << time_span2.count() << '\n';
    }

    file1.close();
    file2.close();
    set_erase(set1);
    set_erase(set2);

    return 0;
}