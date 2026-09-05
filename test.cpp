#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> values;
    int tempValue;
    char choice;

    std::cout << "=== Error Calculation & Data Collection Program ===" << std::endl;
    std::cout << "Enter integers one by one.\n" << std::endl;

    while (true) {
        std::cout << "Enter integer #" << (values.size() + 1) << ": ";
        
        while (!(std::cin >> tempValue)) {
            std::cout << "Warning: Invalid input! Bruh, you gotta enter an actual integer: ";
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        values.push_back(tempValue);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "You tryna add another value? (y/n): ";
        std::cin >> choice;
        
        if (choice == 'n' || choice == 'N') {
            break;
        }
        std::cout << std::endl;
    }

    if (values.empty()) {
        std::cout << "\nNo values entered. The math isn't mathing, exiting program." << std::endl;
        return 0;
    }

    double sum = 0;
    for (int val : values) {
        sum += val;
    }
    double mean = sum / values.size();

    double absoluteErrorSum = 0;
    for (int val : values) {
        absoluteErrorSum += std::abs(val - mean);
    }
    double meanAbsoluteError = absoluteErrorSum / values.size();

    std::cout << "\n=== Results ===" << std::endl;
    std::cout << "Total values entered: " << values.size() << std::endl;
    std::cout << "Calculated Mean (Average): " << mean << std::endl;
    std::cout << "Mean Absolute Error: " << meanAbsoluteError << std::endl;

    return 0;
}