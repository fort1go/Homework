#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//Стек
struct StackNode {
    char data;
    StackNode* next;
};

struct Stack {
    StackNode* top;
};

Stack* createStack() {
    Stack* stack = new Stack;
    stack->top = nullptr;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == nullptr;
}

void add(Stack* stack, char value) {
    StackNode* node = new StackNode;
    node->data = value;
    node->next = stack->top;
    stack->top = node;
}

char remove(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    StackNode* node = stack->top;
    char value = node->data;
    stack->top = node->next;
    delete node;
    return value;
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->top->data;
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack* stack = createStack();
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (c == ' ') continue;
        
        if (isdigit(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            add(stack, c);
        }
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = remove(stack);
            }
            if (!isEmpty(stack)) {
                remove(stack);
            }
        }
        else if (isOperator(c)) {
            while (!isEmpty(stack) && 
                   isOperator(peek(stack)) && 
                   priority(peek(stack)) >= priority(c)) {
                postfix[j++] = remove(stack);
            }
            add(stack, c);
        }
    }
    
    while (!isEmpty(stack)) {
        postfix[j++] = remove(stack);
    }
    
    postfix[j] = '\0';
}

int main() {
    const int MAX_SIZE = 1000;
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    cout << "Введите выражение: ";
    cin.getline(infix, MAX_SIZE);
    
    infixToPostfix(infix, postfix);
    
    cout << "Постфиксная форма: " << postfix << endl;
    
    return 0;
}
