#ifndef SAJAT_TIPUSOK_H_INCLUDED
#define SAJAT_TIPUSOK_H_INCLUDED
#include "memtrace.h"
#define MEMTRACE

#include <string>

namespace myNspace {
    static const int kep_szelesseg = 1024;
    static const int kep_magassag = 768;


    struct koordinata {
        int x;
        int y;
    };

    struct float_3d_koord {
        float x;
        float y;
        float z;
        float w;
    };


    struct rgba_szin {
        int r;
        int g;
        int b;
        int a;
    };

    enum utasitas_enum {
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

    struct uzenet {
        std::string kuldo_ID;
        std::string cimzett_ID;
        std::string tartalom;
        std::string adat;
    };

};



#endif // SAJAT_TIPUSOK_H_INCLUDED
