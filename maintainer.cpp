//
// Created by simon on 2020. 06. 18..
//

#include "maintainer.h"

void Maintainer::clearScreen() {
    SDL_SetRenderDrawColor(sdl->getRenderer(), 50, 50, 50, 255);
    static SDL_Rect background;
    background.x = 0; background.y = 0; background.w = my::window_width; background.h = my::window_height;
    SDL_RenderFillRect(sdl->getRenderer(), &background);
}

void Maintainer::display () {
    SDL_RenderPresent(sdl->getRenderer());
}