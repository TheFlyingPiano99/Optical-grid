//
// Created by simon on 2020. 06. 18..
//

#ifndef OPTICAL_GRID_LIGHT_SOURCE_H
#define OPTICAL_GRID_LIGHT_SOURCE_H


#include <cmath>
#include <iostream>

/**
 * Lézer fényforrás
 */
class Laser {
    float wavelength;
    float intensity;
    float wavenumber;
    float angular_velocity;
    float electric_field_amp;


public:
    /**
     * konstruktor
     * @param wl - hullámhossz [m]
     * @param i - intenzitás [W/m^2]
     */
    Laser(float wl, float i):wavelength(wl), intensity(i) {
        electric_field_amp = sqrtf(intensity) * 27.45248394;
        wavenumber = (float)6.283185307 / wavelength;
        angular_velocity = wavenumber * (float)299792458;
    }

    float getWavelength() {
        return wavelength;
    }

    float getIntensity() {
        return intensity;
    }

    float getElectric_field_amp () {
        return electric_field_amp;
    }

    float getWavenumber () {
        return wavenumber;
    }

    float getAngular_velocity() {
        return angular_velocity;
    }
};

#endif //OPTICAL_GRID_LIGHT_SOURCE_H
