#pragma once

#include <iostream>
#include <vector>
#include "OCP_Prototype.h"

class Command {
public:
    virtual void execute() = 0;
};

// Concrete Commands
class TaskCommand : public Command {
private:
    SalariedEmployee* employee;

public:
    TaskCommand(SalariedEmployee* emp) : employee(emp) {}

    void execute() override {
        employee->doTask();
    }
};

// Invoker
class CEO {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* command) {
        commands.push_back(command);
    }

    void delegateTasks() {
        std::cout << "CEO is delegating tasks:" << std::endl;
        for (Command* command : commands) {
            command->execute();
        }
    }
};