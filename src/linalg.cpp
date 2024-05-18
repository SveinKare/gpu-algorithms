#include <linalg.hpp>
#include <vector>
#include <stdexcept>
#include <thread>
#include <iostream>


namespace linalg {
    Matrix::Matrix(size_t rows, size_t cols) {
        this->rows = rows;
        this->cols = cols;
        this->data = new int[rows * cols];
        for (size_t i = 0; i < rows * cols; i++) {
            this->data[i] = 0;
        }
    }

    Matrix::~Matrix() {
        delete[] this->data;
    }

    int Matrix::get(size_t row, size_t col) {
        return this->data[row * this->cols + col];
    }

    void Matrix::set(size_t row, size_t col, int value) {
        this->data[row * this->cols + col] = value;
    }

    size_t Matrix::getRows() {
        return this->rows;
    }

    size_t Matrix::getCols() {
        return this->cols;
    }

    void Matrix::print() {
        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                std::cout << this->get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    int dotProduct(std::vector<int> a, std::vector<int> b, int size) {
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += a[i] * b[i];
        }
        return result;
    }

    int threadedDotProduct(std::vector<int> a, std::vector<int> b, int size, int threads) {
        int chunkSize = size / threads;
        std::vector<int> results(threads);
        std::vector<std::thread> threadPool;
        for (int i = 0; i < threads; i++) {
            threadPool.push_back(std::thread([i, chunkSize, &a, &b, &results, threads] {
                int start = i * chunkSize;
                int end = (i + 1) * chunkSize;
                if (i >= threads - 1) {
                    end = a.size();
                }
                results[i] = dotProduct(std::vector<int>(a.begin() + start, a.begin() + end),
                                        std::vector<int>(b.begin() + start, b.begin() + end),
                                        end - start);
            }));
        }
        for (int i = 0; i < threads; i++) {
            threadPool[i].join();
        }
        int result = 0;
        for (int i = 0; i < threads; i++) {
            result += results[i];
        }
        return result;
    }

    Matrix matrixMultiplication(Matrix a, Matrix b) {
        if (a.getCols() != b.getRows()) {
            throw std::runtime_error("Matrix dimensions do not match");
        }
        Matrix result(a.getRows(), b.getCols());
        for (size_t i = 0; i < a.getRows(); i++) {
            for (size_t j = 0; j < b.getCols(); j++) {
                int value = 0;
                for (size_t k = 0; k < a.getCols(); k++) {
                    value += a.get(i, k) * b.get(k, j);
                }
                result.set(i, j, value);
            }
        }
        return result;
    }

    Matrix threadedMatrixMultiplication(Matrix a, Matrix b, int threads) {
        return Matrix(0, 0);
    }
}