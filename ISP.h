#pragma once

#include <iostream>

// Interface Segregation Principle (ISP)

class Lobbist {
public:
    virtual void wait() = 0;
};

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

class Waiter : public Worker, public Eater, public Lobbist {
public:
    void work() override {
        std::cout << "Waiter is working." << std::endl;
    }

    void eat() override {
        std::cout << "Waiter is eating." << std::endl;
    }

    void wait() override {
        std::cout << "Waiter is waiting." << std::endl;
    }
};

class HR : public Lobbist {
public:
    void wait() override {
        std::cout << "Sits and doesen't do anything as always :)" << std::endl;
    }
};