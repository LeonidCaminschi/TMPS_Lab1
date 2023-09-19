#include <iostream>
#include <vector>

using namespace std;

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

// Open/Closed Principle (OCP)

class Employee {
public:
    virtual double calculatePay() const = 0;
};

class HourlyEmployee : public Employee {
public:
    double calculatePay() const override {
        // Calculate pay for hourly employees
        return 10.0 * 40.0; // $10 per hour for 40 hours
    }
};

class SalariedEmployee : public Employee {
public:
    double calculatePay() const override {
        // Calculate pay for salaried employees
        return 4000.0; // Monthly salary of $4000
    }
};

// Liskov Substitution Principle (LSP)

class Manager : public Employee {
public:
    double calculatePay() const override {
        // Calculate pay for managers
        return 5000.0; // Monthly salary of $5000
    }
};

// Interface Segregation Principle (ISP)

class Worker {
public:
    virtual void work() = 0;
};

class Eater {
public:
    virtual void eat() = 0;
};

class Engineer : public Worker, public Eater {
public:
    void work() override {
        std::cout << "Engineer is working." << std::endl;
    }

    void eat() override {
        std::cout << "Engineer is eating." << std::endl;
    }
};

class Waiter : public Worker, public Eater {
public:
    void work() override {
        std::cout << "Waiter is working." << std::endl;
    }

    void eat() override {
        std::cout << "Waiter is eating." << std::endl;
    }
};

// Dependency Inversion Principle (DIP)

class EmployeeService {
private:
    PayCalculator payCalculator;
    EmployeeRepository employeeRepository;

public:
    EmployeeService(const PayCalculator& pc, const EmployeeRepository& er)
            : payCalculator(pc), employeeRepository(er) {}

    void processPayroll(const Employee& employee) {
        double pay = employee.calculatePay();
        std::cout << "Pay calculated: $" << pay << std::endl;
        employeeRepository.saveEmployee();
    }
};

int main() {
    PayCalculator payCalculator;
    EmployeeRepository employeeRepository;
    EmployeeService employeeService(payCalculator, employeeRepository);

    std::vector<Employee*> employees;
    employees.push_back(new HourlyEmployee());
    employees.push_back(new SalariedEmployee());
    employees.push_back(new Manager());

    for (const auto& employee : employees) {
        employeeService.processPayroll(*employee);
        delete employee;
    }

    Engineer engineer;
    Waiter waiter;

    engineer.work();
    waiter.eat();

    return 0;
}