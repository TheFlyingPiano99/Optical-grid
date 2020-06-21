//
// Created by simon on 2020. 05. 26..
//

#include <stdexcept>
#include "matrix.h"
#include "Analise.h"

template<typename t, typename T>
Matrix<t> operator*(Matrix<t>& mx1, Matrix<T>& mx2) {
    size_t c1r2 = mx1.getColumnN();
    if (c1r2 != mx2.getRowN()) {
        throw "Hibas mertu matrix!";
    }

    size_t r1 = mx1.getRowN();
    size_t c2 = mx2.getColumnN();

    Matrix<t> retM(r1, c2);

    for (size_t i = 0; i < r1; i++) {
        for (size_t  j = 0; j < c2; j++) {
            for (size_t  k = 0; k < c1r2; k++) {
                retM[i][j] = mx1[i][k] * mx2[k][j];
            }
        }
    }

    return retM;
}

template<typename t, typename T>
Matrix<T> operator*(Matrix<t>& mx1, Matrix<T>& mx2) {
    size_t c1r2 = mx1.getColumnN();
    if (c1r2 != mx2.getRowN()) {
        throw "Hibas mertu matrix!";
    }

    size_t r1 = mx1.getRowN();
    size_t c2 = mx2.getColumnN();

    Matrix<t> retM(r1, c2);

    for (size_t i = 0; i < r1; i++) {
        for (size_t  j = 0; j < c2; j++) {
            for (size_t  k = 0; k < c1r2; k++) {
                retM[i][j] = mx1[i][k] * mx2[k][j];
            }
        }
    }

    return retM;
}
