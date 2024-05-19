

# MLLA (C++)

This repository contains a C++ library designed to perform a variety of matrix operations which are foundational for applications in machine learning and data science.

## Features

- **Basic Matrix Operations**: Addition, subtraction, and scalar multiplication.
- **Matrix Multiplication**: Includes both element-wise multiplication and matrix product.
- **Utility Functions**: Transpose, matrix equality, and identity matrix generation.
- **Advanced Operations**: Matrix inversion and determinant calculation (planned or under development).
- **Integration with Google Test**: Comprehensive unit tests using Google Test.

## Getting Started

### Prerequisites

- CMake (version 3.10 or higher)
- A C++ compiler supporting C++11 (e.g., GCC, Clang)
- Google Test (included as a submodule or using CMake's FetchContent)

### Building the Project

Clone the repository and navigate to the project directory:

```bash
git clone https://github.com/yourusername/nn_cpp.git
cd nn_cpp
```

Create a build directory and run CMake to configure the project:

```bash
mkdir build && cd build
cmake ..
make
```

### Running Tests

After building the project, you can run the unit tests to ensure everything is working correctly:

```bash
./MatrixTests
```

## Usage

Here is a simple example of how to use the Matrix class:

```cpp
#include <iostream>
#include "matrix.h"
using namespace std;


int main() {
    // Creating a 3x3 matrix
    Matrix A = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};


    Matrix I = Matrix::identity(3); // Creating an identity matrix of size 3
    Matrix result = A.matMul(I); // Multiplying A by the identity matrix
    result.print();                    // Print the result

    cout << "-----------------------" << endl;

    // Create a row vector
    Matrix rowVector = {{1, 2, 3, 4}};

    // Create a 4x3 matrix to multiply with the row vector
    Matrix someMatrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
    };

    // Perform matrix multiplication (row vector x matrix)
    // The result should be a 1x3 matrix (row vector)
    Matrix result2 = rowVector.matMul(someMatrix);

    // Print the result
    std::cout << "Result of multiplying row vector by matrix:" << std::endl;
    result2.print();

    return 0;
}
```
### Terminal Output
```
1 2 3 
4 5 6 
7 8 9 
-----------------------
Result of multiplying row vector by matrix:
70 80 90 
```
## Contributing

Contributions are welcome! If you have suggestions for improvements or bug fixes, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.