//
// Created by simon on 2020. 06. 18..
//

#include "optical_grid.h"

void Optical_grid::diffract (Laser* laser,  float distance_to_layer,  Light_sensitive_layer* layer, float t) {
    size_t x_layersize = layer->getWidth() ;
    size_t y_layersize = layer->getHeight();

    ///meter / felület-pixel:
    float m_per_layer_dot = layer->getMeterPerPixel();

    ///Egy pont, ahol egy rés található:
    my::float_4d_coord slit_pos;
    slit_pos.y = 0;
    slit_pos.z = 0;
    slit_pos.w = 0;
    ///Egy pont, ahol felületre érkező fény intezitását mérjük:
    my::float_4d_coord layer_point_pos;

    layer_point_pos.z = distance_to_layer;
    layer_point_pos.w = 0;

    float x_slit_offset = ((float)n/2) * d;


    for (size_t x = 0; x < x_layersize; x++) {
        for (size_t y = 0; y < y_layersize; y++) {
            layer_point_pos.x = ((float)x - x_layersize / 2) * m_per_layer_dot;
            layer_point_pos.y = ((float)y- y_layersize / 2) * m_per_layer_dot;


            float electric_field = 0;
            for (size_t i = 0; i < n; i++) {
                slit_pos.x = (float)i * d - x_slit_offset;
                my::float_4d_coord dirrection = layer_point_pos - slit_pos;
                float distance_travelled = abs_float_3d_koord(dirrection);
                my::float_4d_coord layer_norm = {0, 0, -1, 0};

                electric_field += laser->getElectric_field_amp() * sinf(laser->getWavenumber() * distance_travelled
                         + laser->getAngular_velocity() * t) * sin(layer_norm, dirrection);

            }
            float poynting = electric_field * electric_field * 0.00265379;
            layer->LightInpact(x, y, poynting);

        }
    }

}
