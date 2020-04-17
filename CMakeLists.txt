cmake_minimum_required(VERSION 3.16)
project(algorithmic_languages_2_lab_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithmic_languages_2_lab_4
        sources/main.cpp
        sources/standard_exceptions.cpp
        sources/raii.cpp
)
target_include_directories(algorithmic_languages_2_lab_4
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
)