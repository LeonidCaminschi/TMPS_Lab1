#pragma once

#include "SRP.h"
#include "OCP_Prototype.h"

#include "Singleton.h"

// Dependency Inversion Principle (DIP)

class EmployeeService {
private:
    PayCalculator payCalculator;
    EmployeeRepository employeeRepository;
    Logger &logger;

public:
    EmployeeService(const PayCalculator& pc, const EmployeeRepository& er, Logger& logger1)
            : payCalculator(pc), employeeRepository(er), logger(logger1) {}

    void processPayroll(Employee& employee) {
        double pay = employee.calculatePay();
        std::cout << "Pay calculated: $" << pay << std::endl;
        logger.log("Pay calculated: $" + std::to_string(pay));
        employeeRepository.saveEmployee();
    }
};