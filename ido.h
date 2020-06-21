#ifndef IDO_H_INCLUDED
#define IDO_H_INCLUDED

#include <SDL.h>
#include "memtrace.h"
#define MEMTRACE


class Ido {
    float delta_t;
    float elozo_t;
    float jelenlegi_t;
public:
    void fps_kiir(SDL_Renderer* renderer);
    void ido_szamitas ();
    const float getDeltat () {
        return delta_t;
    }
};



#endif // IDO_H_INCLUDED
