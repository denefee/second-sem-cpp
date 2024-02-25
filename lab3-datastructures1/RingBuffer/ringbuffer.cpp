#include <iostream>

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
    int n = 10;
    int k = 2;
    RingBuffer* buffer = create_ring_buffer(n);
    
    std::cout << "The survivor for n = " << n << " and k = " << k << " is: ";
    while (buffer->current != nullptr) {
        std::cout << Josephus(buffer, k) << " ";
    }
    std::cout << std::endl;

    erase(buffer);

    return 0;
}
