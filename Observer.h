#pragma once

#include <iostream>
#include <vector>

class Component {
public:
    virtual void update(const std::string& newState) = 0;
};

class Controller {
private:
    std::vector<class Component*> observers;
    std::string state;

public:
    void addComponent(Component* observer) {
        observers.push_back(observer);
    }

    void notifyComponents() {
        for (Component* observer : observers) {
            observer->update(state);
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notifyComponents();
    }
};

class ConcreteComponent : public Component {
private:
    std::string observerState;

public:
    void update(const std::string& newState) override {
        observerState = newState;
        std::cout << "Component updated with state: " << observerState << std::endl;
    }
};