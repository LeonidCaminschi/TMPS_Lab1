#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "ObjectPooling.h"

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance; // Guaranteed to be initialized only once
        return instance;
    }

    void log(const std::string& message) {
        std::ofstream logFile("log.txt", std::ios::app);
        if (logFile.is_open()) {
            time_t rawTime;
            struct tm* timeInfo;
            char buffer[80];

            time(&rawTime);
            timeInfo = localtime(&rawTime);

            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

            logFile << "[" << buffer << "] " << message << std::endl;
            logFile.close();
        }
    }

private:
    Logger() {} // Private constructor to enforce Singleton pattern

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    ~Logger() {

    }
};