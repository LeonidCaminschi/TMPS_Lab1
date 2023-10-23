#pragma once

#include "ISP.h"

class Decorator : public Lobbist {
protected:
    Lobbist* lob;

public:
    Decorator(Lobbist* comp) : lob(comp) {}

    void wait() override {
        lob->wait();
    }
};

class Hobo : public Decorator {
public:
    Hobo(Lobbist* lob) : Decorator(lob) {}

    void wait() override {
        Decorator::wait();
        cout << "Hobo waits infinelty :)" << endl;
    }
};