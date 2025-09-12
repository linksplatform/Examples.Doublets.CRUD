cmake_minimum_required(VERSION 3.13)

project(Examples.Doublets.CRUD.Cpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add conan packages if available
if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake")
    include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

# Find required packages
find_package(Platform.Interfaces)
find_package(Platform.Collections.Methods)
find_package(Platform.Collections)
find_package(Platform.Numbers)
find_package(Platform.Memory)
find_package(Platform.Exceptions)
find_package(Platform.Data)
find_package(Platform.Setters)
find_package(Platform.Ranges)
find_package(mio)

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

# Set C++20 standard
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

# Link required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Interfaces::Platform.Interfaces)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Collections.Methods::Platform.Collections.Methods)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Collections::Platform.Collections)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Numbers::Platform.Numbers)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Memory::Platform.Memory)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Exceptions::Platform.Exceptions)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Data::Platform.Data)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Setters::Platform.Setters)
target_link_libraries(${PROJECT_NAME} PRIVATE Platform.Ranges::Platform.Ranges)
target_link_libraries(${PROJECT_NAME} PRIVATE mio::mio)

# Add additional linker libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_DL_LIBS})

# Include the Platform.Data.Doublets headers if available locally
# This assumes the Platform.Data.Doublets repository is available
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../Platform.Data.Doublets")
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Platform.Data.Doublets/cpp)
endif()