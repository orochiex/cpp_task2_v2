cmake_minimum_required(VERSION 3.27)
project(Task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task2 main.cpp
        Client.h
        Client.cpp
        Bank.h
        Bank.cpp
        Account.h
        Account.cpp
        BankSystem.h
        BankSystem.cpp
)
