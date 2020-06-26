//
// Created by simon on 2020. 06. 18..
//

#ifndef TELESZKOP_LIGHT_SENSITIVE_LAYER_H
#define TELESZKOP_LIGHT_SENSITIVE_LAYER_H

#include <SDL.h>

#include "matrix.h"
#include "resource.h"
#include "my_types.h"


/** Fényérékeny felület
 * Ezen jelenik meg a diffrakciós kép
 */
class Light_sensitive_surface {
    Matrix<std::deque<float>> poynting_history;
    Matrix<float> intensity;
    float m_per_dot;
    //std::vector<float> frotier;

public:
    /**
     * konstruktor
     * @param w - felület szélessége pixelekben kifejezve
     * @param h - felület magassága pixelekben kifejezve
     * @param m_p_pix - egy pixel oldalhossza méterben kifejezve
     */
    Light_sensitive_surface(size_t w, size_t h, float m_p_pix): poynting_history(w, h), intensity(w, h), m_per_dot(m_p_pix) {
        intensity.clear();
    }

    /**
     * Egy adott időpillanatban a fényérzékeny felület egy adott pontjára merőleges poynting vektor beállítása.
     * @param x - a felület x koordinátája
     * @param y - a felület y koordinátája
     * @param s - a felületre merőleges poynting vektor nagysága
     */
    void LightInpact (int x, int y, float s);

    /**
     * A teljes fényérzékeny felület kirajzolása. A nagyobb intnzitás zöldebb.
     *
     * @param renderer - SDL renderelő címe
     * @param x1 - bal felső x pozíció az ablakban
     * @param y1 - bal felső y pozíció az ablakban
     * @param x2 - jobb alsó x pozíció az ablakban
     * @param y2 - jobb alsó y pozíció az ablakban
     * @param brightness - a megjelenítés fényessége (Kompenzálni lehet vele a túl nagy
     *                     vagy kis intenzitású diffrakciós képet.)
     */
    void plot2D (SDL_Renderer* renderer, int x1, int y1, int x2, int y2, float brightness);

    /**
     * A fényérzékeny felület egy metszetének kirajzolása a x = {felület középpontjától mért távolság}
     * és az y = {adott helyen mért intenzitás} grafikonon.
     * @param renderer - SDL renderelő címe
     * @param wr - szöveg kiíró objektum címe
     * @param x1 - bal felső x pozíció az ablakban
     * @param y1 - bal felső y pozíció az ablakban
     * @param x2 - jobb alsó x pozíció az ablakban
     * @param y2 - jobb alsó y pozíció az ablakban
     */
    void plot1D (SDL_Renderer* renderer, Writer* wr, int x1, int y1, int x2, int y2);


    size_t getWidth () {
        return poynting_history.getRowN();
    }

    size_t getHeight () {
        return poynting_history.getColumnN();
    }

    float getMeterPerPixel () const {
        return m_per_dot;
    }
};

#endif //TELESZKOP_LIGHT_SENSITIVE_LAYER_H
