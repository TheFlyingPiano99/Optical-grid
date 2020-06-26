//
// Created by simon on 2020. 06. 18..
//

#include "optical_grid.h"

void Optical_grid::diffract (Laser* laser, float distance_to_surface, Light_sensitive_surface* surface, float t) {
    ///Felület méretei:
    size_t x_surfacesize = surface->getWidth() ;
    size_t y_surfacesize = surface->getHeight();

    ///méter / felület-pixel oldal:
    float m_per_surface_dot = surface->getMeterPerPixel();

    ///Egy pont, ahol egy rés található:
    my::float_4d_coord slit_pos;
    slit_pos.y = 0;
    slit_pos.z = 0;
    slit_pos.w = 0;

    ///Egy pont, ahol a felületre érkező fény poynting vektorát számítjuk:
    my::float_4d_coord surface_point_pos;

    surface_point_pos.z = distance_to_surface;
    surface_point_pos.w = 0;

    float x_slit_offset = ((float)n/2) * d; ///A rések pozicionálására szolgál, hogy a diffrakciós kép középen jelenjen meg.

    ///Felületen iterálás:
    for (size_t x = 0; x < x_surfacesize; x++) {
        for (size_t y = 0; y < y_surfacesize; y++) {
            surface_point_pos.x = ((float)x - x_surfacesize / 2) * m_per_surface_dot;
            surface_point_pos.y = ((float)y - y_surfacesize / 2) * m_per_surface_dot;

            float electric_field = 0;
            ///Réseken iterálás:
            for (size_t i = 0; i < n; i++) {
                slit_pos.x = (float)i * d - x_slit_offset;
                my::float_4d_coord direction = surface_point_pos - slit_pos;
                float distance_travelled = abs_float_3d_koord(direction);
                my::float_4d_coord layer_norm = {0, 0, -1, 0}; ///felület normál vektora

                electric_field += laser->getElectric_field_amp() * sinf(laser->getWavenumber() * distance_travelled
                         + laser->getAngular_velocity() * t) * sin(layer_norm, direction);

            }
            surface->LightInpact(x, y, electric_field * electric_field * 0.00265379);
        }
    }

}
