#pragma once

#include <iostream>

class ProgramingLanguage {
private:
    std::string language;
public:
    std::string getLanguage() {
        return language;
    }

    void setLanguage(std::string newlang) {
        language = newlang;
    }

    void yourLanguage() {
        if (language == "python") std::cout << "high level" << std::endl;
        if (language == "c++") std::cout << "low level" << std::endl;
        if (language == "Some other bs") std::cout << "BS dont use" << std::endl;
    }
};

class DesignPatterns {
private:
    std::string pattern;
public:
    std::string getPattern() {
        return pattern;
    }

    void setPattern(std::string newpat) {
        pattern = newpat;
    }

    void yourPattern() {
        if (pattern == "decorator") std::cout << "Structrural" << std::endl;
        if (pattern == "prototype") std::cout << "Creational" << std::endl;
        if (pattern == "Some other bs") std::cout << "BS dont use" << std::endl;
    }
};

class Facade {
private:
    ProgramingLanguage pl;
    DesignPatterns dp;
public:
    void execute (std::string newnew) {
        if (newnew == "c++") {
            pl.setLanguage(newnew);
            pl.yourLanguage();
        }
        else {
            dp.setPattern(newnew);
            dp.yourPattern();
        }
    }
};