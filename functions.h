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

#include "my_types.h"

float abs_float_3d_koord (my::float_4d_coord k);

typename my::float_4d_coord norm_float_3d_koord(my::float_4d_coord a);

typename my::float_4d_coord operator-(my::float_4d_coord a, my::float_4d_coord b);

typename my::float_4d_coord operator+(my::float_4d_coord a, my::float_4d_coord b);

typename my::float_4d_coord operator*(my::float_4d_coord a, my::float_4d_coord b);

typename my::float_4d_coord operator*(float a, my::float_4d_coord b);
typename my::float_4d_coord operator*(my::float_4d_coord b, float a);

float dot_product(my::float_4d_coord a, my::float_4d_coord b);
typename my::float_4d_coord cross_product(my::float_4d_coord a, my::float_4d_coord b);
float sin(my::float_4d_coord v1, my::float_4d_coord v2);


#endif //LEGITARSASAG_FUNCTIONS_H
