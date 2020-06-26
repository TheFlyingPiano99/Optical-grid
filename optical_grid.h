//
// Created by simon on 2020. 06. 18..
//

#ifndef TELESZKOP_GRID_H
#define TELESZKOP_GRID_H

#include "light_source.h"
#include "light_sensitive_layer.h"
#include "functions.h"

/**
 *Optikai rács
 */
class Optical_grid {
    size_t n;
    float d;

public:
    /**
     * konstruktor
     * @param n - rések száma
     * @param d - rések közötti távolság [m]
     */
    Optical_grid(size_t n , float d): n(n), d(d) {}

    /**
     * Diffrakció végrehajtása lézerfényen x távolságban lévő felületre vetítve:
     * @param laser - fényforrás címe
     * @param distance_to_surface - távolság a rács és a fényérzékeny felület között [m]
     * @param surface - fényérzékeny felület címe
     * @param t - idő változó
     */
    void diffract (Laser* laser, float distance_to_surface, Light_sensitive_surface* surface, float t);

};

#endif //TELESZKOP_GRID_H
