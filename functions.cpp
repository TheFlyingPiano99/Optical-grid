//
// Created by simon on 2020. 05. 25..
//

#include "functions.h"

float abs_float_3d_koord (my::float_4d_coord k) {
    return std::sqrt(k.x*k.x + k.y*k.y + k.z*k.z + k.w*k.w);
}

typename my::float_4d_coord operator-(my::float_4d_coord a, my::float_4d_coord b) {
    my::float_4d_coord ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    ret.z = a.z - b.z;
    ret.w = a.w - b.w;
    return ret;
}

typename my::float_4d_coord operator+(my::float_4d_coord a, my::float_4d_coord b) {
    my::float_4d_coord ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    ret.z = a.z + b.z;
    ret.w = a.w + b.w;
    return ret;
}

typename my::float_4d_coord operator*(my::float_4d_coord a, my::float_4d_coord b) {
    my::float_4d_coord ret;
    ret.x = a.x * b.x;
    ret.y = a.y * b.y;
    ret.z = a.z * b.z;
    ret.w = a.w * b.w;
    return ret;
}

typename my::float_4d_coord operator*(float a, my::float_4d_coord b) {
    b.x = a * b.x;
    b.y = a * b.y;
    b.z = a * b.z;
    b.w = a * b.w;
    return b;
}

typename my::float_4d_coord operator*(my::float_4d_coord b, float a) {
    b.x = a * b.x;
    b.y = a * b.y;
    b.z = a * b.z;
    b.w = a * b.w;
    return b;
}

typename my::float_4d_coord norm_float_3d_koord(my::float_4d_coord a) {
    float abs = abs_float_3d_koord(a);
    a.x = a.x / abs;
    a.y = a.y / abs;
    a.z = a.z / abs;
    a.w = a.w / abs;
    return a;
}

float dot_product(my::float_4d_coord a, my::float_4d_coord b) {
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}


float cos_angle (my::float_4d_coord v1, my::float_4d_coord v2) {

    return dot_product(v1, v2) / (abs_float_3d_koord(v1) * abs_float_3d_koord(v2));
}

float sin (my::float_4d_coord v1, my::float_4d_coord v2) {
    return dot_product(v1, v2) / (abs_float_3d_koord(v1) * abs_float_3d_koord(v2));
}
