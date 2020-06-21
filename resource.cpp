#include "resource.h"
#include "sajat_sdl.h"
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

bool Writer::beolvas_textura(SDL* sdl, const char* ut, int atlatszo_szin) {
    return sdl->texturaOlvasas(&texturak, ut, atlatszo_szin);
}

void Writer::bmp_karakter_kivalasztasa(char c, SDL_Rect& mezo) {
    c -= 32; //0. => 'space'
    int sor = c/karakter_egy_sorban;
    int oszlop = c%karakter_egy_sorban;
    //std::cout << (int)c << " oszlop: " << oszlop << ", sor: " << sor << std::endl;
    mezo.x = oszlop * kw;
    mezo.y = sor * kh;
}

void Writer::szoveg_kiir(SDL_Renderer* renderer, const char* str, int x, int y, int max_szelesseg) {
    SDL_Rect mezo;
    mezo.w = kw;
    mezo.h = kh;
    SDL_Rect celhely;
    celhely.x = x;
    celhely.y = y;
    celhely.w = kw;
    celhely.h = kh;
    int szelesseg = 0;
    int hossz = strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((hossz * kw > max_szelesseg) && ((szelesseg+ 4*kw) > max_szelesseg)) {
            for (int j = 0; j < 3; j++) {
                bmp_karakter_kivalasztasa('.', mezo);
                SDL_RenderCopy(renderer, bmp_font, &mezo, &celhely);
                szelesseg += kw;
                celhely.x = x + szelesseg;
            }
            break;
        }
        bmp_karakter_kivalasztasa(str[i], mezo);
        SDL_RenderCopy(renderer, bmp_font, &mezo, &celhely);
        szelesseg += kw;
        celhely.x = x + szelesseg;
    }

}

bool Writer::beolvas_bmp_font(SDL* sdl, const char* ut) {
    bool visszateres = Writer::beolvas_textura(sdl, ut, 0x000000);
    if (visszateres) {
        bmp_font = texturak.back();
    }
    return visszateres;
}
