#ifndef SAJAT_TIPUSOK_H_INCLUDED
#define SAJAT_TIPUSOK_H_INCLUDED
#include "memtrace.h"
#define MEMTRACE

#include <string>

namespace my {
    static const int window_width = 1024;
    static const int window_height = 768;


    struct int_2d_coord {
        int x;
        int y;
    };

    struct float_4d_coord {
        float x;
        float y;
        float z;
        float w;
    };


    struct rgba_colour {
        int r;
        int g;
        int b;
        int a;
    };

    enum control_event_enum {
        kilep,
        interakcio,
        fel,
        le,
        jobbra,
        balra,
        eger_bal_klikk,
        eger_bal_felenged,
        eger_jobb_klikk,
        eger_jobb_felenged,
        eger_mozgas,
        eger_gorgetes,
        nincs_utasitas
    };

    struct event {
        std::string kuldo_ID;
        std::string cimzett_ID;
        std::string tartalom;
        std::string adat;
    };

};



#endif // SAJAT_TIPUSOK_H_INCLUDED
