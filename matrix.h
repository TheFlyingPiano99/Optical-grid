//
// Created by simon on 2020. 05. 26..
//

#ifndef LEGITARSASAG_MATRIX_H
#define LEGITARSASAG_MATRIX_H

#include <complex>
#include <vector>

template<typename t = std::complex<float>>
class Matrix {
    size_t row;
    size_t column;
    std::vector<std::vector<t>> mx;
public:
    Matrix(size_t r, size_t c): row(r), column(c) {
        mx.resize(row);
        for (size_t i = 0; i < row; i++) {
            mx[i].resize(column);
        }
    }
    std::vector<t>& operator[] (int i) {
        return mx[i];
    }

    template<const size_t c2>
    Matrix<t> operator*( Matrix<t>& mx2);

    void clear() {
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < column; j++) {
                mx[i][j] = 0.0;
            }
        }
    }

    int getRowN () {
        return row;
    }

    int getColumnN () {
        return column;
    }

};

template<const int r1,const  int c2,const  int c1r2>
Matrix<std::complex<float>> operator*(Matrix<std::complex<float>>& mx1, Matrix<std::complex<float>>& mx2);

Matrix<std::complex<float>> operator*(Matrix<float>& mx1, Matrix<>& mx2);

#endif //LEGITARSASAG_MATRIX_H
