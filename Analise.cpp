//
// Created by simon on 2020. 05. 25..
//

#include "Analise.h"

void Analiser::create_discrete_fourier_transform_mx (const std::complex<float>& omega, Matrix<>& ebbe) {
    size_t N = ebbe.getRowN();
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            ebbe[i][j] = pow(omega, i * j);
        }
    }

}


void Analiser::discrete_fourier_transform(Matrix<float>& f, Matrix<std::complex<float>>& f_transform) {
    const int N = f.getColumnN();

    std::complex<float> omega = expf(2 * M_PI / N);

    Matrix<> transf_mx(N, N);
    create_discrete_fourier_transform_mx(omega, transf_mx);
/*
    f_transform = f * transf_mx;


    int maxT = 200
    double sum_re = 0;
    double sum_im = 0;
    for (int t = 0; t < maxT; t++ ) {
        double szog = (2* 3.14159265359 * omega * t) / maxT;
        sum_re += f(t) * cos(szog);
        sum_im += f(t) * sin(szog);
    }

    return sqrt(sum_re * sum_re  +  sum_im   * sum_im);
*/
}

void Analiser::discrete_fourier_transform_sajat(std::vector<float>& f, std::vector<float>& f_transform) {
    size_t maxT = f.size();


    for (size_t omega = 0; omega < maxT; omega++) {

        float sum_re = 0;
        float sum_im = 0;

        for (size_t t = 0; t < maxT; t++ ) {
            double szog = (2* 3.14159265359 * omega * t) / maxT;
            sum_re += f[t] * cos(szog);
            sum_im += f[t] * sin(szog);
        }
        f_transform.push_back(sqrt(sum_re * sum_re  +  sum_im  * sum_im));
    }

}

