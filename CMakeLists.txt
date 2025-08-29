cmake_minimum_required(VERSION 3.10)
project(LoginSystem)

set(CMAKE_CXX_STANDARD 17)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug or Release)" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Add debug flags if Debug build
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Include header files
include_directories(include)

# Source files
add_executable(login_app
    src/main.cpp
    src/auth.cpp
)

# Link OpenSSL libraries
target_link_libraries(login_app OpenSSL::SSL OpenSSL::Crypto)
