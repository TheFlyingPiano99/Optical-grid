//
// Created by simon on 2020. 05. 25..
//

#ifndef LEGITARSASAG_ANALISE_H
#define LEGITARSASAG_ANALISE_H
#include <cmath>
#include "matrix.h"
#include <vector>


class Functions;

class Analiser {

    void create_discrete_fourier_transform_mx (const std::complex<float>& omega, Matrix<>& ebbe);

public:
    Analiser() {}


    void discrete_fourier_transform(Matrix<float>& f, Matrix<std::complex<float>>& f_transform);

    void discrete_fourier_transform_sajat(std::vector<float>& f, std::vector<float>& f_transform);

};

#endif //LEGITARSASAG_ANALISE_H
