cmake_minimum_required(VERSION 3.17)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 20)

set(SRC src/basic_gates/basic_gates.cpp
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
        src/IComponent.hpp
        src/Component.cpp
        src/Component.hpp
        src/Circuit.cpp
        src/Circuit.hpp
        src/Parser.cpp
        src/Parser.hpp
        src/Exception.cpp
        src/Exception.hpp
        src/main.cpp)


add_executable(nanotekspice ${SRC})