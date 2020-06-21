//
// Created by simon on 2020. 06. 18..
//

#ifndef TELESZKOP_MAINTAINER_H
#define TELESZKOP_MAINTAINER_H
#include "sajat_sdl.h"

class Maintainer {
    SDL* sdl;
public:
    Maintainer(SDL* s): sdl(s) {}

    void clearScreen();
    void display ();
};


#endif //TELESZKOP_MAINTAINER_H
