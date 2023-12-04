#include <iostream>

class PowerCalculator {
public:
    virtual double calculatePower(double n, int p) = 0;
};

class RecursivePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double n, int p) override {
        if (p == 0) {
            return 1.0;
        } else if (p == 1) {
            return n;
        } else {
            return n * calculatePower(n, p - 1);
        }
    }
};

class IterativePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double n, int p) override {
        double result = 1.0;
        for (int i = 0; i < p; i++) {
            result *= n;
        }
        return result;
    }
};

int main() {
    double n;
    int p;

    std::cout << "Enter the base value: ";
    std::cin >> n;

    std::cout << "Enter the power value: ";
    std::cin >> p;

    // Create an instance of RecursivePowerCalculator
    RecursivePowerCalculator recursiveCalculator;
    double recursiveResult = recursiveCalculator.calculatePower(n, p);

    // Create an instance of IterativePowerCalculator
    IterativePowerCalculator iterativeCalculator;
    double iterativeResult = iterativeCalculator.calculatePower(n, p);

    std::cout << "Recursive power: " << recursiveResult << std::endl;
    std::cout << "Iterative power: " << iterativeResult << std::endl;

    return 0;
}
