//
// Created by Michael Tamburello on 5/19/24.
//
#include "../include/matrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Matrix::Matrix(size_t m, size_t n) : m(m), n(n), data(m, vector<double>(n, 0.0)) {}

Matrix::Matrix(initializer_list<initializer_list<double>> initData) {
    m = initData.size();
    n = initData.begin()->size();
    data.resize(m);
    size_t i = 0;
    for (const auto& row: initData) {
        if (row.size() != n) throw std::invalid_argument("All rows must be same size");
        data[i++] = row;
    }
}

Matrix::Matrix(initializer_list<double> initData) {
    m = initData.size();
    n = 1;
    data.resize(m);
    size_t i = 0;
    for (double val: initData) {
        data[i++].push_back(val);
    }

}

double& Matrix::operator()(size_t i, size_t j) {
    return data.at(i).at(j);
}

const double& Matrix::operator()(size_t i, size_t j) const {
    return data.at(i).at(j);
}


double Matrix::getElement(size_t i, size_t j) const {
    return data.at(i).at(j);
}

size_t Matrix::numRows() const {
    return m;
}

size_t Matrix::numCols() const {
    return n;
}

Matrix Matrix::transpose() const {
    Matrix transposedMatrix(n, m); // swapped dims not typo
    for (size_t i=0; i < m; i++) {
        for (size_t j=0; j < n; j++) {
            transposedMatrix(j, i) = data[i][j];
        }
    }
    return transposedMatrix;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (double elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}



Matrix Matrix::operator+(const Matrix& other) const {
    if (m != other.numRows() || n != other.numCols()) throw invalid_argument("Matrices must be identical in shape");
    Matrix result(m, n);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            result(i, j) = data[i][j] + other.getElement(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (m != other.numRows() || n != other.numCols()) throw invalid_argument("Matrices must be identical in shape");
    Matrix result(m, n);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            result(i, j) = data[i][j] - other.getElement(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (m != other.numRows() || n != other.numCols()) throw invalid_argument("Matrices must be identical in shape");
    Matrix result(m, n);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            result(i, j) = data[i][j] * other.getElement(i, j);
        }
    }
    return result;
}

Matrix operator*(const Matrix& mat, double scalar) {
    Matrix result(mat.numRows(), mat.numCols());
    for (size_t i = 0; i < mat.numRows(); i++) {
        for (size_t j = 0; j < mat.numCols(); j++) {
            result(i, j) = mat.getElement(i, j) * scalar;
        }
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& mat) {
    return mat * scalar;
}


Matrix Matrix::identity(size_t n) {
    Matrix identityMatrix(n, n);
    for (size_t i = 0; i < n; i++) {
        identityMatrix(i, i) = 1.0;
    }
    return identityMatrix;
}

Matrix Matrix::matMul(const Matrix& other) {
    if (this->numCols() != other.numRows()) throw invalid_argument("Matrix dims are not compatible");
    Matrix result(this->numRows(), other.numCols());
    for (size_t i=0; i < this->numRows(); i++) {
        for (size_t j=0; j < other.numCols(); j++) {
            for (size_t k=0; k < this->numCols(); k++) {
                result(i, j) += this->getElement(i, k) * other.getElement(k, j);
            }
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix &other) const {
    if (m != other.numRows() || n != other.numCols()) {
        return false;
    }
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            if (data[i][j] != other.getElement(i, j)) {
                return false;
            }
        }
    }
    return true;
}
