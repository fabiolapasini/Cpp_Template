# C++ CMake + vcpkg Template

This repository is a template project designed to quickly bootstrap a modern C++ application using:

- **CMake**
- **vcpkg**
- **OpenCV**
- **nlohmann-json**
- **GoogleTest (gtest)**

The project provides a clean and scalable structure for developing C++ applications with dependency management, unit testing, and configurable runtime settings.

---

# Requirements

Before building the project, make sure the following tools are installed on your machine:

- CMake >= 3.22.1
- vcpkg
- A C++ compiler supporting C++17 or newer
- Visual Studio / MSVC (Windows) or GCC/Clang (Linux/macOS)

---

# Technologies Used

## CMake

The project uses CMake as the build system generator.

Minimum required version:

```cmake
cmake_minimum_required(VERSION 3.22.1)
