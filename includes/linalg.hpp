#include <vector>

#ifndef LINALG_HPP
#define LINALG_HPP

namespace linalg {
    class Matrix {
        public:
            Matrix(size_t rows, size_t cols);
            ~Matrix();

            int get(size_t row, size_t col);
            void set(size_t row, size_t col, int value);
            size_t getRows();
            size_t getCols();
            void print();
        private:
            size_t rows;
            size_t cols;
            int* data; 
    };

    int dotProduct(std::vector<int> a, std::vector<int> b, int size);

    int threadedDotProduct(std::vector<int> a, std::vector<int> b, int size, int threads);

    Matrix matrixMultiplication(Matrix a, Matrix b);

    Matrix threadedMatrixMultiplication(Matrix a, Matrix b, int threads);
}
#endif