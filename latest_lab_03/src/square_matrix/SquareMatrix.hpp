// SquareMatrix.hpp

#include "SquareMatrix.h"

template<typename T>
SquareMatrix<T>::SquareMatrix() : size(0) {}

template<typename T>
SquareMatrix<T>::SquareMatrix(size_t n, T initial_value) : size(n) {
    matrix.resize(n, std::vector<T>(n, initial_value));
}

template<typename T>
size_t SquareMatrix<T>::getSize() const {
    return size;
}

template<typename T>
void SquareMatrix<T>::Resize(size_t new_size, const T& initial_value) {
    if (new_size == size)
        return;

    std::vector<std::vector<T>> new_matrix(new_size, std::vector<T>(new_size, initial_value));

    for (size_t i = 0; i < std::min(size, new_size); ++i) {
        for (size_t j = 0; j < std::min(size, new_size); ++j) {
            new_matrix[i][j] = matrix[i][j];
        }
    }

    size = new_size;
    matrix = std::move(new_matrix);
}


template<typename T>
T& SquareMatrix<T>::at(size_t row, size_t col) {
    return matrix[row][col];
}

template<typename T>
const T& SquareMatrix<T>::at(size_t row, size_t col) const {
    return matrix[row][col];
}

template<typename T>
std::vector<T>& SquareMatrix<T>::operator[](size_t row) {
    return matrix[row];
}

template<typename T>
const std::vector<T>& SquareMatrix<T>::operator[](size_t row) const {
    return matrix[row];
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix<T>& other) const {
    SquareMatrix<T> result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result[i][j] = matrix[i][j] + other[i][j];
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator+=(const SquareMatrix<T>& other) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] += other[i][j];
        }
    }
    return *this;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const SquareMatrix<T>& other) const {
    SquareMatrix<T> result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                result[i][j] += matrix[i][k] * other[k][j];
            }
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator*=(const SquareMatrix<T>& other) {
    *this = *this * other;
    return *this;
}

template<typename T>
std::vector<T> SquareMatrix<T>::MultiplyLeft(const std::vector<T>& vec) const {
    std::vector<T> result(size, T());
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

template<typename T>
std::vector<T> SquareMatrix<T>::MultiplyRight(const std::vector<T>& vec) const {
    std::vector<T> result(size, T());
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result[j] += matrix[i][j] * vec[i];
        }
    }
    return result;
}
