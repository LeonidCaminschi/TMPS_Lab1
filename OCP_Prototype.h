#pragma once

// Open/Closed Principle (OCP)

class Employee {
public:
    virtual double calculatePay() = 0;
    virtual Employee* clone() const = 0;
    virtual void ShowInfo() const = 0;
};

class HourlyEmployee : public Employee {
public:
    HourlyEmployee(float MinPay) : MinimumPay(MinPay) {}

    HourlyEmployee() {}

    float getSalary() {
        return MinimumPay;
    }

    double calculatePay() override {
        // Calculate pay for hourly employees
        return getSalary() * 40.0; // $10 per hour for 40 hours
    }

    void ShowInfo() const override {
        std::cout << "minimum pay for this particular type of worker is: " << MinimumPay << "$ per hour" << std::endl;
    }

    Employee* clone() const override {
        return new HourlyEmployee(MinimumPay);
    }


private:
    float MinimumPay = 10;
};

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(bool HI) : HealthInsurance(HI) {}

    SalariedEmployee() {}

    double calculatePay() override {
        // Calculate pay for salaried employees
        return 4000.0; // Monthly salary of $4000
    }

    bool hasHealthInsurance() {
        return HealthInsurance;
    }

    void ShowInfo() const override {
        std::cout << "This particular worker " << (HealthInsurance ? "has" : "doesen't have") << " health insurance" << std::endl;
    }

    Employee* clone() const override {
        return new SalariedEmployee(HealthInsurance);
    }
private:
    bool HealthInsurance = true;
};
