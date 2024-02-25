#include <iostream>

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
    current->next = head;

    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            current = current->next;
        }
        LinkedList* to_remove = current->next;
        current->next = to_remove->next;
        delete to_remove;
    }

    std::cout << "The survivor for n = " << n << " and k = " << k << " is: ";
    std::cout << current->data << std::endl;
    current->next = nullptr;
    return current;
}

int main() {
    josephus(7, 3);

    return 0;
}
