# Topic: *SOLID Principles*
## Author: *Caminschi Leonid*
------
## Objectives:
&ensp; &ensp; __1. Study and understand the SOLID Principles.__

&ensp; &ensp; __2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.__

&ensp; &ensp;__3. Create a sample project that respects SOLID Principles.__

## Theory:
&ensp; &ensp; SOLID is a set of five object-oriented design principles intended to make software designs more maintainable, flexible, and easy to understand. The acronym stands for Single Responsibility Principle, Open-Closed Principle, Liskov Substitution Principle, Interface Segregation Principle, and Dependency Inversion Principle. Each principle addresses a specific aspect of software design, such as the organization of responsibilities, the handling of dependencies, and the design of interfaces. By following these principles, software developers can create more modular, testable, and reusable code that is easier to modify and extend over time. These principles are widely accepted and adopted in the software development community and can be applied to any object-oriented programming language.
   
## Main tasks:
&ensp; &ensp; __1. Choose an OO programming language and a suitable IDE or Editor (No frameworks/libs/engines allowed).__

&ensp; &ensp; __2. Select a domain area for the sample project.__

&ensp; &ensp; __3. Define the main involved classes and think about what instantiation mechanisms are needed.__

&ensp; &ensp; __4. Respect SOLID Principles in your project.__

## Code examples of SOLID Principles:

## Single Responsibility Principle (SRP)

The Single Responsibility Principle (SRP) states that a class should have only one reason to change. In this block of code, we demonstrate SRP by separating responsibilities related to payroll calculation and employee data persistence.

```
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
```

In this section, `PayCalculator` handles payroll calculations, while `EmployeeRepository` manages employee data persistence. This separation adheres to SRP by ensuring that each class has a single responsibility.

---

## Open/Closed Principle (OCP)

The Open/Closed Principle (OCP) encourages software entities to be open for extension but closed for modification. Here, we demonstrate OCP by creating an extensible structure for handling different types of employees.

```
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

class Manager : public Employee {
public:
    double calculatePay() const override {
        // Calculate pay for managers
        return 5000.0; // Monthly salary of $5000
    }
};
```

In this section, we have base `Employee` class and derived classes for various employee types. This design allows you to add new employee types without modifying existing code, following the OCP.

---

## Liskov Substitution Principle (LSP)

The Liskov Substitution Principle (LSP) ensures that derived classes can be used interchangeably with their base classes without affecting program correctness. In this code block, we demonstrate LSP with employee types.

```
class Manager : public Employee {
public:
    double calculatePay() const override {
        // Calculate pay for managers
        return 5000.0; // Monthly salary of $5000
    }
};
```

The `Manager` class, as a derived class of `Employee`, can be used interchangeably with other employee types, adhering to LSP.

---

## Interface Segregation Principle (ISP)

The Interface Segregation Principle (ISP) suggests creating small, focused interfaces. In this block, we demonstrate ISP with interfaces for worker and eater roles.

```
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
```

In this section, we define focused interfaces `Worker` and `Eater`. Classes like `Engineer` and `Waiter` implement only the methods they need, following ISP.

---

## Dependency Inversion Principle (DIP)

The Dependency Inversion Principle (DIP) suggests depending on abstractions rather than concrete implementations. In this code block, we demonstrate DIP in the `EmployeeService` class.

```
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
```

The `EmployeeService` class depends on abstractions (`PayCalculator` and `EmployeeRepository`), allowing for flexibility in choosing implementations while adhering to DIP.

---

These code blocks demonstrate the SOLID principles in action. Each principle contributes to a well-structured, maintainable, and extensible codebase.

## Conclusion


In conclusion, given laboratory work on SOLID principles emphasized the significance of these fundamental software design principles - Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion. I applied these principles to refactor and enhance a software project, demonstrating their ability to reduce complexity, improve organization, and facilitate long-term maintainability. I also recognized the benefits of SOLID principles in fostering collaboration among developers and ensuring software systems remain adaptable in a rapidly changing environment. As software engineers, integrating these principles into our practices is crucial for creating durable, adaptable, and high-quality software.
