#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>

// Function to load values for variables a-f from a file
void loadVariableValues(int vars[6], const std::string& filename) {
    std::cout << "Trying to open file: " << filename << std::endl; // Debug line
    std::ifstream inputFile(filename);
    if (!inputFile) {
        throw std::runtime_error("Unable to open file: " + filename);
    }
    for (int i = 0; i < 6; i++) {
        inputFile >> vars[i];
    }
    inputFile.close();
}


// Function to substitute variables a-f in the expression with values from vars array
std::string substituteVariables(const std::string& expression, int vars[6]) {
    std::string result;
    for (char ch : expression) {
        if (ch >= 'a' && ch <= 'f') {
            result += std::to_string(vars[ch - 'a']);
        } else {
            result += ch;
        }
    }
    return result;
}

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix notation
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix;

    for (char ch : infix) {
        if (std::isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Remove '(' from stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to perform an arithmetic operation
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
    }
    throw std::runtime_error("Invalid operator");
}

// Function to evaluate a postfix expression
int evaluatePostfix(const std::string& postfix) {
    std::stack<int> values;

    for (char ch : postfix) {
        if (std::isdigit(ch)) {
            values.push(ch - '0');
        } else {
            int operand2 = values.top(); values.pop();
            int operand1 = values.top(); values.pop();
            int result = applyOperation(operand1, operand2, ch);
            values.push(result);
        }
    }

    return values.top();
}

int main() {
    int vars[6];
    loadVariableValues(vars, "variables.txt");

    // Example infix expression
    std::string infix = "(a+b)*(c-d)";

    // Substitute variables a-f with corresponding values from vars array
    infix = substituteVariables(infix, vars);

    // Convert infix to postfix notation
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    std::cout << "Evaluated result: " << result << std::endl;

    return 0;
}
