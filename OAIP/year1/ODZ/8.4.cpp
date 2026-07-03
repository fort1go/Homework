#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* sortList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* sorted = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        if (sorted == nullptr || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    Node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->next = head;
        head = newNode;
    }
    cout << "Исходный список: ";
    printList(head);
    head = sortList(head);
    cout << "Отсортированный список: ";
    printList(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
