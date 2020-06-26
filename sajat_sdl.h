#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
#include <vector>
#include <string>
#include <map>
#include <SDL.h>

#include "my_types.h"
#include "memtrace.h"
#include "control.h"
#include "time.h"

#define MEMTRACE

class ControlEvents;
class Menu_elem;
struct SDL_Texture;
class Writer;
class Jatek_entitas;
class SDL_Window;
class SDL_Renderer;

class InitError : public std::exception
{
    std::string msg;
public:
    InitError();
    InitError( const std::string & );
    virtual ~InitError() throw();
    virtual const char * what() const throw();


};

class SDL
{
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
public:
    SDL( Uint32 flags = 0 ) {
        if ( SDL_Init( flags ) != 0 )
            throw InitError();

        if ( SDL_CreateWindowAndRenderer(my::window_width, my::window_height, SDL_WINDOW_SHOWN,
                                         &m_window, &m_renderer ) != 0 )
            throw InitError();
    }

    virtual ~SDL() {
        SDL_DestroyWindow( m_window );
        SDL_DestroyRenderer( m_renderer );
        SDL_Quit();
    }

    virtual void rajzol(/*std::map<std::string, Jatek_entitas*>& jobjektuml,*/ Menu_elem& menu, Writer& forras, Time& jido);
    void billentyu_olvasas(ControlEvents& utasitasok);

    bool texturaOlvasas(std::vector <SDL_Texture*>* texturak, const char* ut, int atlatszo_szin = -1) {
        SDL_Surface *felulet = SDL_LoadBMP(ut);
        if (NULL != felulet) {
            if (0 <= atlatszo_szin) {
                SDL_SetColorKey(felulet, SDL_TRUE, atlatszo_szin);
            }

            //Format optimalizalas:
            SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGB332);
            felulet = SDL_ConvertSurface(felulet, format, 0);
            SDL_FreeFormat(format);

            SDL_Texture* uj_textura = SDL_CreateTextureFromSurface(m_renderer, felulet);
            texturak->push_back(uj_textura);
            SDL_FreeSurface(felulet);
            return true;
        }
        else {
            throw "Nem sikerult beolvasni egy texturat!";
        }
        return false;
    }

    void ikonAllitas(const char* ut) {
        SDL_Surface* ikon = SDL_LoadBMP(ut);
        if (NULL != ikon) {
            SDL_SetWindowIcon(m_window, ikon);
            SDL_FreeSurface(ikon);
        }
        else
            throw "Nem sikerult beolvasni az ikon forrasat!";
    }

    SDL_Renderer* getRenderer() {
        return m_renderer;
    }

    SDL_Window* getWindow() {
        return m_window;
    }
};





#endif // SDL_H_INCLUDED
