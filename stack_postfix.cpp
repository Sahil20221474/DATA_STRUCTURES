#include <iostream>
#include <stack>
#include <string>

// Function to evaluate a postfix expression using a stack
int evaluatePostfix(std::string expression) {
    std::stack<int> stack;

    for (char& c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    std::string postfixExpression = "34+5*";

    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    int result = evaluatePostfix(postfixExpression);

    std::cout << "Result of the expression: " << result << std::endl;

    return 0;
}
