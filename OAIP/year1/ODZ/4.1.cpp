#include <iostream>
#include <fstream>
using namespace std;

struct StackNode {
    char data;
    StackNode* next;
};

void stackPush(StackNode*& top, char value) {
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char stackPop(StackNode*& top) {
    if (top == nullptr) return '\0';
    StackNode* temp = top;
    char value = top->data;
    top = top->next;
    delete temp;
    return value;
}

void clearStack(StackNode*& top) {
    while (top != nullptr) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    ifstream inputFile("input.txt");
    
    StackNode* stack = nullptr;
    char c;
    
    while (inputFile.get(c)) {
        stackPush(stack, c);
    }
    
    inputFile.close();
    
    while (stack != nullptr) {
        cout << stackPop(stack);
    }
    
    clearStack(stack);
    
    return 0;
}
