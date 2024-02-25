#include <iostream>
#include <chrono>

struct LinkedList {
    int data;
    LinkedList* next;
};

LinkedList* insert_after(LinkedList*  const current, int data) {
    LinkedList* new_node = new LinkedList{data, nullptr};
    if (current != nullptr) {
        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}

LinkedList* remove_after(LinkedList*  const current) {
    if (current == nullptr || current->next == nullptr) {
        return nullptr;
    }
    LinkedList* removed_node = current->next;
    current->next = removed_node->next;
    delete removed_node;
    return current->next;
}

void erase(LinkedList*  const head) {
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* to_remove = current;
        current = current->next;
        delete to_remove;
    }
}

LinkedList* josephus(int n, int k) {
    if (n < 1 || k < 1) {
        return nullptr;
    }

    LinkedList* head = new LinkedList{1, nullptr};
    LinkedList* current = head;
    for (int i = 2; i <= n; ++i) {
        current = insert_after(current, i);
    }
    current->next = head; // make the list circular

    while (current->next != current) {
        for (int i = 1; i < k; ++i) {
            current = current->next;
        }
        LinkedList* to_remove = current->next;
        current->next = to_remove->next;
        delete to_remove;
    }
    current->next = nullptr; // liquidate memory leaks
    return current;
}


int main() {
    for (int n = 50; n <= 750; n += 50) {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 10; i++) {
            for (int k = 2; k < n; k++) {
                josephus(n, k);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/(10*(n - 2)));
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}
