#include <iostream>
#include <stack>
#include <sstream>

// Function to check if the character is an operand
bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

// Function to perform an operation
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}

// Function to evaluate the prefix expression using a stack
int evaluatePrefixExpression(const std::string& expression) {
    std::stack<int> operandStack;

    for (int i = expression.length() - 1; i >= 0; --i) {
        if (isOperand(expression[i])) {
            operandStack.push(expression[i] - '0');
        } else {
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();
            int result = performOperation(expression[i], operand1, operand2);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    // Example prefix expression: 5 + 2*3
    std::string prefixExpression = "+5*23";

    std::cout << "Prefix Expression: " << prefixExpression << std::endl;

    int result = evaluatePrefixExpression(prefixExpression);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
