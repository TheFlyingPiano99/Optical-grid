//
// Created by simon on 2020. 06. 18..
//

#ifndef TELESZKOP_LIGHT_SENSITIVE_LAYER_H
#define TELESZKOP_LIGHT_SENSITIVE_LAYER_H

#include "matrix.h"
#include <SDL.h>
#include "resource.h"

#include "sajat_tipusok.h"

class Light_sensitive_layer {
    Matrix<float> poynting;
    Matrix<std::deque<float>> poynting_history;
    Matrix<float> intensity;
    float m_per_dot;
    //std::vector<float> frotier;

public:
    Light_sensitive_layer(size_t w, size_t h, float m_p_pix): poynting(w, h), poynting_history(w, h), intensity(w, h), m_per_dot(m_p_pix) {
        poynting.clear();
        intensity.clear();
        //frotier.resize(w);

    }

    void LightInpact (int x, int y, float s);

    void plot2D (SDL_Renderer* renderer, int x1, int y1, int x2, int y2, float dimming);

    void plot1D (SDL_Renderer* renderer, Writer* wr, int x1, int y1, int x2, int y2);


    size_t getWidth () {
        return poynting.getRowN();
    }

    size_t getHeight () {
        return poynting.getColumnN();
    }
    float getMeterPerPixel () {
        return m_per_dot;
    }
};

#endif //TELESZKOP_LIGHT_SENSITIVE_LAYER_H
