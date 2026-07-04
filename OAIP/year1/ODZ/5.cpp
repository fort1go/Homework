#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct StackNode {
    char data;
    StackNode* next;
};

struct NumStackNode {
    double data;
    NumStackNode* next;
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

void numStackPush(NumStackNode*& top, double value) {
    NumStackNode* newNode = new NumStackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

double numStackPop(NumStackNode*& top) {
    if (top == nullptr) return 0.0;
    NumStackNode* temp = top;
    double value = top->data;
    top = top->next;
    delete temp;
    return value;
}

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    StackNode* stack = nullptr;
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (c == ' ') continue;
        
        if (isdigit(c)) {
            postfix[j++] = c;
            if (!isdigit(infix[i+1]) && infix[i+1] != '.') {
                postfix[j++] = ' ';
            }
        }
        else if (c == '(') {
            stackPush(stack, c);
        }
        else if (c == ')') {
            while (stack != nullptr && stack->data != '(') {
                postfix[j++] = stackPop(stack);
                postfix[j++] = ' ';
            }
            stackPop(stack);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (stack != nullptr &&
                   (stack->data == '+' || stack->data == '-' ||
                    stack->data == '*' || stack->data == '/') &&
                   getPriority(stack->data) >= getPriority(c)) {
                postfix[j++] = stackPop(stack);
                postfix[j++] = ' ';
            }
            stackPush(stack, c);
        }
    }
    
    while (stack != nullptr) {
        postfix[j++] = stackPop(stack);
        postfix[j++] = ' ';
    }
    
    if (j > 0) postfix[j-1] = '\0';
    else postfix[0] = '\0';
}

double evaluatePostfix(const char* postfix) {
    NumStackNode* stack = nullptr;
    int i = 0;
    
    while (postfix[i] != '\0') {
        if (postfix[i] == ' ') {
            i++;
            continue;
        }
        
        if (isdigit(postfix[i])) {
            double num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            numStackPush(stack, num);
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || 
                 postfix[i] == '*' || postfix[i] == '/') {
            double b = numStackPop(stack);
            double a = numStackPop(stack);
            double result = 0;
            
            switch(postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            numStackPush(stack, result);
            i++;
        }
        else {
            i++;
        }
    }
    
    return numStackPop(stack);
}

double calculate(const char* infix) {
    char postfix[256];
    infixToPostfix(infix, postfix);
    return evaluatePostfix(postfix);
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    char infix[256];
    char postfix[256];
    
    cout << "Введите арифметическое выражение: ";
    cin.getline(infix, 256);
    
    infixToPostfix(infix, postfix);
    cout << "Постфиксная форма: " << postfix << endl;
    
    double result = evaluatePostfix(postfix);
    cout << "Результат вычисления: " << result << endl;
    
    return 0;
}
