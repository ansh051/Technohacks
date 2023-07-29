#include <iostream>

int main() {
    char operatorSymbol;
    double num1, num2, result;

    // Input
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operatorSymbol;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform the calculation
    switch (operatorSymbol) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            return 1;
    }

    // Output the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
