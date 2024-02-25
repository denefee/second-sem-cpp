#include <iostream>
#include <chrono>

struct LinkedList {
    int data;
    LinkedList* next;
};

struct RingBuffer {
    LinkedList* current;
    LinkedList* last;
};

RingBuffer* create_ring_buffer(int n) {
    RingBuffer* buffer = new RingBuffer{};
    for (int i = 1; i <= n; i++) {
        LinkedList* new_node = new LinkedList{i, nullptr};
        if (buffer->last == nullptr) {
            buffer->current = new_node;
            buffer->last = new_node;
            new_node->next = new_node;
        } else {
            new_node->next = buffer->current;
            buffer->last->next = new_node;
            buffer->last = new_node;
        }
    }
    return buffer;
}

int Josephus(RingBuffer* buffer, int k) {
    LinkedList* current = buffer->current;
    LinkedList* prev = buffer->last;
    while (current->next != current) {
        // Find the k-th node
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        // Remove the k-th node
        prev->next = current->next;
        if (current == buffer->current) {
            buffer->current = prev->next;
        }
        LinkedList* to_remove = current;
        current = prev->next;
        delete to_remove;
    }
    int survivor = current->data;
    delete current;
    buffer->current = nullptr;
    buffer->last = nullptr;
    return survivor;
}

void erase(RingBuffer* buffer) {
    if (buffer->current != nullptr) {
        LinkedList* current = buffer->current;
        while (current->next != buffer->current) {
            LinkedList* to_remove = current->next;
            current->next = to_remove->next;
            delete to_remove;
        }
        delete current;
        buffer->current = nullptr;
        buffer->last = nullptr;
    }
}

int main() {
    for (int n = 10; n <= 10000; n += 10) {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 10; i++) {         
            RingBuffer* buffer = create_ring_buffer(n);
            while (buffer->current != nullptr) {
                Josephus(buffer, 3);
            }
            erase(buffer);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/(10));
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}
