#include <iostream>

using namespace std;

class PowerException : public exception {
public:
    PowerException(const string& message) : message(message) {}

    const string& getMessage() const {
        return message;
    }

private:
    string message;
};

double power(double n, int p) {
    if (n == 0 && p == 0) {
        throw PowerException("Invalid input: n cannot be 0 when p is 0");
    }

    if (n < 0) {
        throw PowerException("Invalid input: n cannot be negative");
    }

    if (p < 0) {
        throw PowerException("Invalid input: p cannot be negative");
    }

    if (p == 0) {
        return 1.0;
    } else if (p == 1) {
        return n;
    } else {
        return n * power(n, p - 1);
    }
}

int main() {
    double n;
    int p;

    cout << "Enter the base value: ";
    cin >> n;

    cout << "Enter the power value: ";
    cin >> p;

    try {
        double result = power(n, p);
        cout << "The power of " << n << " raised to " << p << " is: " << result << endl;
    } catch (PowerException& e) {
        cerr << "Error: " << e.getMessage() << endl;
    }

    return 0;
}
