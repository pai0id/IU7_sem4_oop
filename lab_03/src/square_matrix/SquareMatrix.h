// SquareMatrix.h

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <vector>
#include <memory>

template <typename T>
class SquareMatrix {
private:
    std::vector<std::vector<T>> matrix;
    size_t size;

public:
    SquareMatrix();
    SquareMatrix(size_t n, T initial_value = T());
    size_t getSize() const;
    void Resize(size_t new_size, const T& initial_value = T());
    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;
    std::vector<T>& operator[](size_t row);
    const std::vector<T>& operator[](size_t row) const;
    SquareMatrix<T> operator+(const SquareMatrix<T>& other) const;
    SquareMatrix<T>& operator+=(const SquareMatrix<T>& other);
    SquareMatrix<T> operator*(const SquareMatrix<T>& other) const;
    SquareMatrix<T>& operator*=(const SquareMatrix<T>& other);
    std::vector<T> MultiplyLeft(const std::vector<T>& vec) const;
    std::vector<T> MultiplyRight(const std::vector<T>& vec) const;
};

#include "SquareMatrix.hpp"

#endif // SQUAREMATRIX_H
