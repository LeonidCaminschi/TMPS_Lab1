#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <memory>

class FileIOPool {
public:
    // Constructor to initialize the pool with a specified size
    FileIOPool(size_t poolSize) {
        for (size_t i = 0; i < poolSize; ++i) {
            fileStreamPool_.emplace_back(std::make_unique<std::ofstream>());
        }
    }

    // Get a file stream from the pool
    std::ofstream& get() {
        std::unique_lock<std::mutex> lock(mutex_);
        for (auto& fileStream : fileStreamPool_) {
            if (!fileStream->is_open()) {
                return *fileStream;
            }
        }
        throw std::runtime_error("No available file streams in the pool.");
    }

    // Release a file stream back to the pool
    void release(std::ofstream& fileStream) {
        std::unique_lock<std::mutex> lock(mutex_);
        fileStream.close();
    }

private:
    std::vector<std::unique_ptr<std::ofstream>> fileStreamPool_;
    std::mutex mutex_;
};