#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFrente(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void insertAtras(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    void mostrar() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoubleLinkedList dll;
    dll.insertFrente(3);
    dll.insertFrente(2);
    dll.insertFrente(1);
    dll.insertAtras(4);
    dll.insertAtras(5);
    
    dll.mostrar();  // Salida: 1 2 3 4 5

    return 0;
}