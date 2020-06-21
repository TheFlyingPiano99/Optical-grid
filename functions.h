//
// Created by simon on 2020. 05. 25..
//

#ifndef LEGITARSASAG_FUNCTIONS_H
#define LEGITARSASAG_FUNCTIONS_H

#include <cmath>

class Functions {
    double amp;
    double omega1;
    double omega2;
public:
    Functions(double a = 1, double o1 = 1, double o2 = 1): amp(a), omega1(o1), omega2(o2) {}

    double sin(double t) {
        return amp * std::sin(omega1 * t);
    }

    double cos(double t) {
        return amp * std::cos(omega2 * t);
    }

    double sin_sin(double t) {
        return amp * (std::sin(omega1 * t) + std::sin(omega2 * t));
    }

    void setAmp(double a) {
        amp = a;
    }


    void setOmega1(double o) {
        omega1 = o;
    }

    void setOmega2(double o) {
        omega1 = o;
    }
};

#include "sajat_tipusok.h"

float abs_float_3d_koord (myNspace::float_3d_koord k);

typename myNspace::float_3d_koord norm_float_3d_koord(myNspace::float_3d_koord a);

typename myNspace::float_3d_koord operator-(myNspace::float_3d_koord a, myNspace::float_3d_koord b);

typename myNspace::float_3d_koord operator+(myNspace::float_3d_koord a, myNspace::float_3d_koord b);

typename myNspace::float_3d_koord operator*(myNspace::float_3d_koord a, myNspace::float_3d_koord b);

typename myNspace::float_3d_koord operator*(float a, myNspace::float_3d_koord b);
typename myNspace::float_3d_koord operator*(myNspace::float_3d_koord b, float a);

float dot_product(myNspace::float_3d_koord a, myNspace::float_3d_koord b);
typename myNspace::float_3d_koord cross_product(myNspace::float_3d_koord a, myNspace::float_3d_koord b);
float sin(myNspace::float_3d_koord v1, myNspace::float_3d_koord v2);


#endif //LEGITARSASAG_FUNCTIONS_H
