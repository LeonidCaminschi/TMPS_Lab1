#pragma once

#include <iostream>

// Single Responsibility Principle (SRP)

class PayCalculator {
public:
    double calculatePay() const {
        // Calculate pay logic
        return 1000.0; // Replace with actual calculation
    }
};

class EmployeeRepository {
public:
    void saveEmployee() {
        // Save employee data to a database
        std::cout << "Employee data saved." << std::endl;
    }
};
