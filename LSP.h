#pragma once

#include "OCP_Prototype.h"

// Liskov Substitution Principle (LSP)

class Manager : public Employee {
public:
    Manager(std::string name1) : name(name1) {}

    Manager() {};

    double calculatePay() override {
        // Calculate pay for managers
        return 5000.0; // Monthly salary of $5000
    }

    void ShowInfo() const override {
        std::cout << "this specific manager is called " << name << std::endl;
    }

    Employee* clone() const override {
        return new Manager(name);
    }
private:
    std::string name;
};