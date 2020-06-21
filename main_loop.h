//
// Created by simon on 2020. 06. 18..
//

#ifndef TELESZKOP_MAIN_LOOP_H
#define TELESZKOP_MAIN_LOOP_H

#include <exception>
#include <iostream>

#include "sajat_sdl.h"
#include "control.h"
#include "functions.h"
#define MEMTRACE

#include "memtrace.h"


class Main {

public:
    int main_func ( int argc, char * argv[] );

    void main_loop (SDL& sdl, Writer& wr);


};

#endif //TELESZKOP_MAIN_LOOP_H
