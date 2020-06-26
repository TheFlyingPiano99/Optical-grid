#include "sajat_sdl.h"


void SDL::rajzol(/*std::map<std::string, Jatek_entitas*>& jentitasl,*/ Menu_elem& menu, Writer& forras, Time& jido)
{
    //H�tt�r kit�rl�se:
    SDL_Rect hatter;
    hatter.x = 0; hatter.y = 0; hatter.w = my::window_width; hatter.h = my::window_height;
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(m_renderer, &hatter);



    //Render kirajzol�sa:
    SDL_RenderPresent(m_renderer);

}

void SDL::billentyu_olvasas(ControlEvents& utasitasok) {
        SDL_Event event;
        while(SDL_PollEvent( &event )) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch( event.key.keysym.sym ) {
                        case SDLK_ESCAPE:
                            utasitasok.pushEvent(my::kilep);
                            break;
                        case SDLK_UP:
                        case SDLK_w:
                            utasitasok.pushEvent(my::fel);
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            utasitasok.pushEvent(my::le);
                            break;
                        case SDLK_LEFT:
                        case SDLK_a:
                            utasitasok.pushEvent(my::balra);
                            break;
                        case SDLK_RIGHT:
                        case SDLK_d:
                            utasitasok.pushEvent(my::jobbra);
                            break;
                        case SDLK_RETURN:
                            utasitasok.pushEvent(my::interakcio);
                            break;
                    }
                    break;
                case SDL_KEYUP:
/*                    switch( event.key.keysym.sym ) {
                        case SDLK_UP:
                        case SDLK_w:
                            utasitasok_vege.uj(fel);
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            utasitasok_vege.uj(le);
                            break;
                        case SDLK_LEFT:
                        case SDLK_a:
                            utasitasok_vege.uj(balra);
                            break;
                        case SDLK_RIGHT:
                        case SDLK_d:
                            utasitasok_vege.uj(jobbra);
                            break;
                        case SDLK_RETURN:
                            utasitasok_vege.pushEvent(interakcio);
                            break;
*/
                        default:
                            break;
                    break;
                case SDL_MOUSEWHEEL:
                        utasitasok.eger_gorgetes(event.wheel.y);
                    utasitasok.pushEvent(my::eger_gorgetes);
                    break;
                case SDL_MOUSEMOTION:
                    my::int_2d_coord xy;
                    SDL_GetMouseState(&(xy.x), &(xy.y));
                    utasitasok.setEger_poz(xy);
                    utasitasok.pushEvent(my::eger_mozgas);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            utasitasok.pushEvent(my::eger_bal_klikk);
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            utasitasok.pushEvent(my::eger_bal_felenged);
                            break;
                    }
                    break;
            }
        }
}

