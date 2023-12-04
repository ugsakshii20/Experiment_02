#include <iostream>

using namespace std;

class PowerCalculator {
private:
    double n;

public:
    PowerCalculator(double n) : n(n) {}

    friend double power(PowerCalculator& calculator, int p);
};

double power(PowerCalculator& calculator, int p) {
    if (calculator.n == 0 && p == 0) {
        throw exception(); // Handle invalid input: n cannot be 0 when p is 0
    }

    if (p < 0) {
        throw exception(); // Handle invalid input: p cannot be negative
    }

    if (p == 0) {
        return 1.0;
    } else if (p == 1) {
        return calculator.n;
    } else {
        return calculator.n * power(calculator, p - 1);
    }
}

int main() {
    double n;
    int p;

    cout << "Enter the base value: ";
    cin >> n;

    cout << "Enter the power value: ";
    cin >> p;

    PowerCalculator calculator(n);

    try {
        double result = power(calculator, p);
        cout << "The power of " << n << " raised to " << p << " is: " << result << endl;
    } catch (exception& e) {
        cerr << "Error: Invalid input" << endl;
    }

    return 0;
}
