#ifndef FORRAS_H_INCLUDED
#define FORRAS_H_INCLUDED

#include <vector>
#include <map>

#include <string.h>
#include "memtrace.h"
#define MEMTRACE

#include <SDL.h>
#include "sajat_sdl.h"

class Writer {
    std::vector <SDL_Texture*> texturak;
    const int koz_x, koz_y;
    const int kw, kh;
    const int karakter_egy_sorban;
    SDL_Texture* bmp_font;

public:
    Writer(): koz_x(0), koz_y(0), kw(10), kh(16), karakter_egy_sorban(18), bmp_font(NULL) {
        texturak = std::vector <SDL_Texture*>();
    }

    ~Writer() {
    }

    bool beolvas_textura(SDL* sdl, const char* ut = "resources/img/ikon.bmp", int atlatszo_szin = -1);

    bool beolvas_bmp_font(SDL* sdl, const char* ut = "resources/font/bmpfont.bmp");


    std::vector <SDL_Texture*>& getTexturak() {
        return texturak;
    }

    void bmp_karakter_kivalasztasa(char c, SDL_Rect& mezo);
    void szoveg_kiir(SDL_Renderer* renderer, const char* str, int x, int y, int max_szelesseg);

};


#endif // FORRAS_H_INCLUDED
