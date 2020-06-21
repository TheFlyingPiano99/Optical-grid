//
// Created by simon on 2020. 06. 18..
//

#ifndef TELESZKOP_GRID_H
#define TELESZKOP_GRID_H

#include "light_source.h"
#include "light_sensitive_layer.h"
#include "functions.h"

/**
 * @param int n - rések száma
 * @param float d - két rés távolsága
 */
class Optical_grid {
    size_t n;
    float d;

public:
    Optical_grid(size_t n , float d): n(n), d(d) {}

    void diffract (Laser* laser, float distance_to_layer, Light_sensitive_layer* layer, float t);

};

#endif //TELESZKOP_GRID_H
