//
// Created by simon on 2020. 05. 25..
//

#include "functions.h"

float abs_float_3d_koord (myNspace::float_3d_koord k) {
    return std::sqrt(k.x*k.x + k.y*k.y + k.z*k.z + k.w*k.w);
}

typename myNspace::float_3d_koord operator-(myNspace::float_3d_koord a, myNspace::float_3d_koord b) {
    myNspace::float_3d_koord ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    ret.z = a.z - b.z;
    ret.w = a.w - b.w;
    return ret;
}

typename myNspace::float_3d_koord operator+(myNspace::float_3d_koord a, myNspace::float_3d_koord b) {
    myNspace::float_3d_koord ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    ret.z = a.z + b.z;
    ret.w = a.w + b.w;
    return ret;
}

typename myNspace::float_3d_koord operator*(myNspace::float_3d_koord a, myNspace::float_3d_koord b) {
    myNspace::float_3d_koord ret;
    ret.x = a.x * b.x;
    ret.y = a.y * b.y;
    ret.z = a.z * b.z;
    ret.w = a.w * b.w;
    return ret;
}

typename myNspace::float_3d_koord operator*(float a, myNspace::float_3d_koord b) {
    b.x = a * b.x;
    b.y = a * b.y;
    b.z = a * b.z;
    b.w = a * b.w;
    return b;
}

typename myNspace::float_3d_koord operator*(myNspace::float_3d_koord b, float a) {
    b.x = a * b.x;
    b.y = a * b.y;
    b.z = a * b.z;
    b.w = a * b.w;
    return b;
}

typename myNspace::float_3d_koord norm_float_3d_koord(myNspace::float_3d_koord a) {
    float abs = abs_float_3d_koord(a);
    a.x = a.x / abs;
    a.y = a.y / abs;
    a.z = a.z / abs;
    a.w = a.w / abs;
    return a;
}

float dot_product(myNspace::float_3d_koord a, myNspace::float_3d_koord b) {
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}


float cos_angle (myNspace::float_3d_koord v1, myNspace::float_3d_koord v2) {

    return dot_product(v1, v2) / (abs_float_3d_koord(v1) * abs_float_3d_koord(v2));
}

float sin (myNspace::float_3d_koord v1, myNspace::float_3d_koord v2) {
    return dot_product(v1, v2) / (abs_float_3d_koord(v1) * abs_float_3d_koord(v2));
}
