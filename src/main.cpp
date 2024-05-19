#include <iostream>
#include <vector>
#include "../include/matrix.h"

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