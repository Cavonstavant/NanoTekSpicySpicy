cmake_minimum_required(VERSION 3.17)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 20)

set(SRC src/basic_gates/basic_gates.cpp
    src/basic_gates/basic_gates.hpp
    src/Components/Component4001.hpp
    src/Components/Component4008.hpp
    src/Components/Component4011.hpp
    src/Components/Component4013.hpp
    src/Components/Component4017.hpp
    src/Components/Component4030.hpp
    src/Components/Component4040.hpp
    src/Components/Component4069.hpp
    src/Components/Component4071.hpp
    src/Components/Component4081.hpp
    src/Components/Component4094.hpp
    src/Components/Component4514.hpp
    src/Components/Component4801.hpp
    src/Components/Component2716.hpp
    src/Components/IOComponent.hpp
    src/Components/Component4001.cpp
    src/Components/Component4008.cpp
    src/Components/Component4011.cpp
    src/Components/Component4013.cpp
    src/Components/Component4017.cpp
    src/Components/Component4030.cpp
    src/Components/Component4040.cpp
    src/Components/Component4069.cpp
    src/Components/Component4071.cpp
    src/Components/Component4081.cpp
    src/Components/Component4094.cpp
    src/Components/Component4514.cpp
    src/Components/Component4801.cpp
    src/Components/Component2716.cpp
    src/Components/IOComponent.cpp)

set(SRC ${SRC}
    src/Circuit.cpp
    src/Circuit.hpp
    src/IComponent.hpp
    src/AComponent.cpp
    src/AComponent.hpp
    src/Parser.cpp
    src/Parser.hpp
    src/Exception.cpp
    src/Exception.hpp
    src/Factory.hpp
    src/Factory.cpp
    src/Simulation.hpp
    src/Simulation.cpp
    src/main.cpp
    src/Components/IOComponent.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
