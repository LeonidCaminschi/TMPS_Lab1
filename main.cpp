#include <vector>

#include "SRP.h"
#include "OCP_Prototype.h"
#include "LSP.h"
#include "ISP.h"
#include "DIP.h"

#include "Singleton.h"
#include "ObjectPooling.h"

#include "Adapter.h"
#include "Decorator.h"
#include "Facade.h"

#include "Command.h"
#include "Observer.h"

using namespace std;

int main() {
    //Object Pooling
    FileIOPool ioPool(1);

    std::ofstream& file1 = ioPool.get();
    file1.open("file1.txt");
    file1 << "This is file 1." << std::endl;
    ioPool.release(file1);
    //End of object pooling
    Logger& logger = Logger::getInstance();

    PayCalculator payCalculator;
    EmployeeRepository employeeRepository;
    EmployeeService employeeService(payCalculator, employeeRepository, logger);

    std::vector<Employee*> employees;
    employees.push_back(new HourlyEmployee());
    employees.push_back(new SalariedEmployee());
    employees.push_back(new Manager());


    //Prototype design pattern
    employees.push_back(employees[2]->clone());
    employees[3]->ShowInfo();
    //End of prototype design pattern

    for (const auto& employee : employees) {
        employeeService.processPayroll(*employee);
        delete employee;
    }

    Engineer engineer;
    Waiter waiter;

    engineer.work();
    waiter.eat();

    // Adapter
    Adapter bbb;
    bbb.wait();

    // Decorator
    HR useless;
    Hobo decoratedHobo(&useless);
    decoratedHobo.wait();

    // Facade
    Facade aaa;
    aaa.execute("c++");

    // Command
    SalariedEmployee employee1;
    SalariedEmployee employee2;

    TaskCommand task1(&employee1);
    TaskCommand task2(&employee2);

    CEO ceo;
    ceo.addCommand(&task1);
    ceo.addCommand(&task2);

    ceo.delegateTasks();

    // Observer
    Controller control;

    ConcreteComponent observer1, observer2;
    control.addComponent(&observer1);
    control.addComponent(&observer2);

    control.setState("Turn component On");

    return 0;
}