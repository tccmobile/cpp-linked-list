# C++ Linked List Implementation

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This project contains a simple implementation of a linked list data structure in C++.

## Development Environment

This project uses Visual Studio Code with the Dev Containers extension. The development environment is automatically set up using Docker.

### Prerequisites

- Docker
- Visual Studio Code
- Dev Containers extension for VS Code

### Getting Started

1. Clone this repository
2. Open in VS Code
3. When prompted, click "Reopen in Container"
4. The development environment will be automatically set up

### Using GitHub Codespaces

As an alternative to local development, you can use GitHub Codespaces:

1. Navigate to the GitHub repository
2. Click the green "Code" button
3. Select the "Codespaces" tab
4. Click "Create codespace on main"

The codespace will automatically:
- Set up the development environment
- Install all necessary extensions
- Configure CMake
- Open the workspace in VS Code in your browser

You can then proceed directly to the [Building and Running](#building-and-running) section.

## Building and Running

This project uses CMake as its build system. To build and run the project:

1. Create a build directory and navigate to it:
   ```bash
   mkdir build && cd build
   ```

2. Generate the build files:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   make
   ```

4. Run the executable:
   ```bash
   ./linked_list
   ```

Alternatively, you can use the CMake Tools extension in VS Code:
1. Click on the CMake Tools status bar item
2. Select "Build" to compile the project
3. Click the play button or select "Run" to execute the program

## Project Structure 
```
cpp-linked-list/
├── src/                 # Source files
│   └── main.cpp        # Main program file
├── .devcontainer/      # Development container configuration
│   ├── devcontainer.json
│   └── Dockerfile
├── CMakeLists.txt      # CMake configuration
├── LICENSE             # MIT License file
└── README.md          # This file
```

## Implementation Details

The project implements a templated double-linked list with the following features:
- Push/pop operations at both ends
- Insertion at any position
- Forward and backward traversal
- Memory management
- Error handling

A practical example using a Task Management System demonstrates the linked list's functionality.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

