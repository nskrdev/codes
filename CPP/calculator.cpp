#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /, %): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero is not allowed!" << endl;
            break;
        case '%':
            // Use int for modulus
            if (static_cast<int>(num2) != 0)
                cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
            else
                cout << "Error: Division by zero in modulus is not allowed!" << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
    }

    return 0;
}
