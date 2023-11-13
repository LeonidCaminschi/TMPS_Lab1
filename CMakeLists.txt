cmake_minimum_required(VERSION 3.26)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 main.cpp
        SRP.h
        OCP_Prototype.h
        LSP.h
        ISP.h
        DIP.h
        Singleton.h
        ObjectPooling.h
        Adapter.h
        Decorator.h
        Facade.h
        Command.h
        Observer.h)
