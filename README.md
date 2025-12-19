# Unit Test Suite

A comprehensive C++ testing suite exploring various aspects of modern C++ with organized modules for different topics.

## Project Structure

```
├── src/                   # Source code (if any reusable components exist)
├── tests/                 # Test files organized by category
│   ├── core/              # Core C++ features and fundamentals
│   ├── templates/         # Template programming tests
│   ├── stl/               # STL containers and algorithms
│   ├── design_patterns/   # Design pattern implementations
│   ├── modern_cpp/        # C++17, C++20, C++23 features
│   ├── algorithms/        # Algorithm-specific tests
│   └── utils/             # Utility and miscellaneous tests
├── include/               # External dependencies (Google Test)
├── docs/                  # Documentation
└── build/                 # Build artifacts
```

## Building and Running Tests

### Prerequisites
- CMake 3.12 or higher
- A C++23 compatible compiler

### Build Instructions
```bash
mkdir build
cd build
cmake ..
make
```

### Run All Tests
```bash
./unit_test
```

### Run Specific Test Categories
```bash
./core_tests          # Core C++ features
./template_tests      # Template programming
./stl_tests           # STL containers and algorithms  
./design_pattern_tests # Design patterns
./modern_cpp_tests    # Modern C++ features
./algorithm_tests     # Algorithms
./utils_tests         # Utilities
```

## Test Categories

### Core C++
Tests covering fundamental C++ features like lambdas, move semantics, const correctness, etc.

### Templates
Template specialization, variadic templates, SFINAE, and other template metaprogramming techniques.

### STL
Performance and functionality tests for STL containers and algorithms.

### Design Patterns
Implementation and testing of common design patterns.

### Modern C++
Tests for C++17, C++20, and C++23 features.

### Algorithms
Sorting, searching, and other algorithm tests.

## Contributing

Add new tests to the appropriate category under the `tests/` directory.