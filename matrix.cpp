#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(std::size_t N) : size_(N), data_(N, std::vector<int>(N, 0)) {}

Matrix::Matrix(std::vector<std::vector<int>> nums) : size_(nums.size()), data_(std::move(nums)) {}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(size_);
    for (std::size_t i = 0; i < size_; ++i) {
        for (std::size_t j = 0; j < size_; ++j) {
            result.data_[i][j] = data_[i][j] + rhs.data_[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(size_);
    for (std::size_t i = 0; i < size_; ++i) {
        for (std::size_t j = 0; j < size_; ++j) {
            for (std::size_t k = 0; k < size_; ++k) {
                result.data_[i][j] += data_[i][k] * rhs.data_[k][j];
            }
        }
    }
    return result;
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i < size_ && j < size_) {
        data_[i][j] = n;
    }
}

int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i < size_ && j < size_) {
        return data_[i][j];
    }
    return 0;
}

int Matrix::get_size() const {
    return size_;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size_; ++i) {
        sum += data_[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size_; ++i) {
        sum += data_[i][size_ - i - 1];
    }
    return sum;
}

void Matrix::swap_rows(std::size_t row1, std::size_t row2) {
    if (row1 < size_ && row2 < size_) {
        std::swap(data_[row1], data_[row2]);
    }
}

void Matrix::swap_cols(std::size_t col1, std::size_t col2) {
    if (col1 < size_ && col2 < size_) {
        for (std::size_t i = 0; i < size_; ++i) {
            std::swap(data_[i][col1], data_[i][col2]);
        }
    }
}

void Matrix::print_matrix() const {
    for (const auto &row : data_) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}
