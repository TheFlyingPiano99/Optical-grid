#include "time.h"

void Time::write_fps(SDL_Renderer* renderer) {
    static unsigned int rajzolas_szam;
    rajzolas_szam += 1;
    static unsigned int elozo_frissites;
    unsigned int eltelt_ido = SDL_GetTicks() - elozo_frissites;
    if (eltelt_ido > 250) {
        //double eltelt_masodperc = eltelt_ido / 1000.0;
        //double fps = rajzolas_szam / eltelt_masodperc;
        //std::cout << "fps: " << fps << std::endl;
        rajzolas_szam = 0;
        elozo_frissites = SDL_GetTicks();
    }
}

void Time::calculate () {
    elozo_t = jelenlegi_t;
    jelenlegi_t = SDL_GetTicks();
    delta_t = jelenlegi_t - elozo_t;
    //Visszaszab alyzas 60 fps-re
    if (delta_t < 16) {
        SDL_Delay(16);
    }
}
