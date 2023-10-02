#pragma once

#include <iostream>

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
