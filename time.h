#ifndef IDO_H_INCLUDED
#define IDO_H_INCLUDED

#include <SDL.h>
#include "memtrace.h"
#define MEMTRACE


class Time {
    float delta_t;
    float elozo_t;
    float jelenlegi_t;
public:
    void write_fps(SDL_Renderer* renderer);
    void calculate ();
    const float getDeltat () {
        return delta_t;
    }
};



#endif // IDO_H_INCLUDED
