#include <iostream>
#include <chrono>

struct DynamicArray  {
    int* elements = nullptr;
    unsigned capacity = 0, size = 0;
};

DynamicArray new_array(unsigned size, int init_val = 0) {
    DynamicArray da;
    da.elements = new int[size];
    da.capacity = size;
    da.size = size;
    for (unsigned i = 0; i < size; i++) {
        da.elements[i] = init_val;
    }
    return da;
}

void erase(DynamicArray &da) {
    delete[] da.elements;
    da.elements = nullptr;
    da.capacity = 0;
    da.size = 0;
}

DynamicArray& reserve(DynamicArray &da, unsigned capacity) {
    if (da.capacity >= capacity) {
        return da;
    }

    int* new_elements = new int[capacity];
    for (unsigned i = 0; i < da.size; i++) {
        new_elements[i] = da.elements[i];
    }
    delete[] da.elements;
    da.elements = new_elements;
    da.capacity = capacity;
    return da;
}

DynamicArray clone(DynamicArray &da) {
    DynamicArray new_da;
    new_da.elements = new int[da.size];
    new_da.capacity = da.size;
    new_da.size = da.size;
    for (unsigned i = 0; i < da.size; i++) {
        new_da.elements[i] = da.elements[i];
    }
    return new_da;
}

DynamicArray& assign(DynamicArray const &src, DynamicArray &dst) {
    if (dst.capacity < src.size) {
        reserve(dst, src.size);
    }
    for (unsigned i = 0; i < src.size; i++) {
        dst.elements[i] = src.elements[i];
    }
    dst.size = src.size;
    return dst;
}

DynamicArray& push_back_str1(DynamicArray &da, int val) {
    // Strategy 1: add exactly one item of memory each time
    if (da.size + 1 > da.capacity ) {
        reserve(da, da.capacity + 1);
    }
    da.elements[da.size] = val;
    da.size++;
    return da;
}

DynamicArray& push_back_str2(DynamicArray &da, int val) {
    // Strategy 2: add memory for a certain fixed number of elements each time
    if (da.size + 1 > da.capacity ) {
        reserve(da, da.capacity + 1000);
    }
    da.elements[da.size] = val;
    da.size++;
    return da;
}

DynamicArray& push_back_str3(DynamicArray &da, int val) {
    // Strategy 3: increase the memory multiple: one and a half or two times
    if (da.size + 1 > da.capacity ) {
        reserve(da, da.capacity * 2);
    }
    da.elements[da.size] = val;
    da.size++;
    return da;
}

void test() {
    DynamicArray da = new_array(5, 1);
    for (int i = 1; i < 100000; i++) {
        auto begin = std::chrono::steady_clock::now();
        da = push_back_str3(da, 2);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin));
        std::cout << time_span.count() << std::endl;
    }
}



int main() {

    test();

    return 0;
}


