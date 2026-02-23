//MAKE A SCIENTIFIC CALCULATOR
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int choice;
    double num1, num2, result;

    cout << "Scientific Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Square Root\n";
    cout << "6. Power\n";
    cout << "7. Sine\n";
    cout << "8. Cosine\n";
    cout << "9. Tangent\n";
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if(num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        case 5:
            cout << "Enter a number: ";
            cin >> num1;
            if(num1 >= 0) {
                result = sqrt(num1);
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Negative input for square root!" << endl;
            }
            break;
        case 6:
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case 7:
            cout << "Enter an angle in degrees: ";
            cin >> num1;
            result = sin(num1 * M_PI / 180);
            cout << "Result: " << result << endl;
            break;
        case 8:
            cout << "Enter an angle in degrees: ";
            cin >> num1;
            result = cos(num1 * M_PI / 180);
            cout << "Result: " << result << endl;
            break;
        case 9:
            cout << "Enter an angle in degrees: ";  
            cin >> num1;
            result = tan(num1 * M_PI / 180);
            cout << "Result: " << result << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    return 0;
}
