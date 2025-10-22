#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    double num1, num2, num3;

    cout << "enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    double largest = max(num1, max(num2, num3));

    cout << "Largest: " << largest << endl;

    return 0;
}
