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

LinkedList* remove_after(LinkedList* const current) {
    if (current == nullptr || current->next == nullptr) {
        return nullptr;
    }
    LinkedList* removed_node = current->next;
    current->next = removed_node->next;
    delete removed_node;
    return current->next;
}

void erase(LinkedList* const head) {
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* to_remove = current;
        current = current->next;
        delete to_remove;
    }
}

LinkedList* reverse_rec(LinkedList* const head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    LinkedList* new_head = reverse_rec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

LinkedList* reverse_itr(LinkedList* const head) {
    LinkedList* prev = nullptr;
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}

int main() {
    LinkedList* head = new LinkedList{1, nullptr};
    LinkedList* node2 = insert_after(head, 2);
    LinkedList* node3 = insert_after(node2, 3);
    LinkedList* node4 = insert_after(node3, 4);
    std::cout << "Original list: ";
    for (LinkedList* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;

    head = reverse_rec(head);
    std::cout << "Reversed recursively: ";
    for (LinkedList* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;

    head = reverse_itr(head);
    std::cout << "Reversed iteratively: ";
    for (LinkedList* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;

    remove_after(head);
    std::cout << "Removed node after head: ";
    for (LinkedList* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;

    erase(head);
    head = nullptr;

    return 0;
}
