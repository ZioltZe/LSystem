cmake_minimum_required(VERSION 3.24)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_library(ProjectLib STATIC
        "src/07_project/Production.cpp"
        "src/07_project/LSystemInterpreter.cpp"
        )

target_include_directories(ProjectLib PRIVATE "include/")

add_executable(TestSuite
        "test/Production.cpp"
        "test/LSystemInterpreter.cpp"
        )

target_include_directories(TestSuite PRIVATE "include/")

target_link_libraries(TestSuite PRIVATE ProjectLib)