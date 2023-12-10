#include<iostream>
using namespace std;

class Power {
public: 
    double base;
    int exponent;

    void getinfo() {
        cout << "Enter the Base of the Number: ";
        cin >> base;
        cout << "Enter the Exponent of the Number: ";
        cin >> exponent;
    }

    void calculatePower() {
        double result = 1.0;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        cout << "The power of " << base << " raised to " << exponent << " is: " << result << endl; 
    }
};

int main() {
    Power p1;
    p1.getinfo();
    p1.calculatePower();
    
    return 0;
}
