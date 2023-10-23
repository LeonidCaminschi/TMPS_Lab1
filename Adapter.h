#pragma once

#include "ISP.h"
#include <iostream>

using namespace std;

class Adapter : public Lobbist {
private:
    Engineer eng;
public:
    virtual void wait() {
        eng.eat();
    }
};