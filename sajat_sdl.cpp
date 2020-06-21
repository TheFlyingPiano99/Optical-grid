#include "sajat_sdl.h"


void SDL::rajzol(/*std::map<std::string, Jatek_entitas*>& jentitasl,*/ Menu_elem& menu, Writer& forras, Ido& jido)
{
    //H�tt�r kit�rl�se:
    SDL_Rect hatter;
    hatter.x = 0; hatter.y = 0; hatter.w = myNspace::kep_szelesseg; hatter.h = myNspace::kep_magassag;
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
                            utasitasok.pushEvent(myNspace::kilep);
                            break;
                        case SDLK_UP:
                        case SDLK_w:
                            utasitasok.pushEvent(myNspace::fel);
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            utasitasok.pushEvent(myNspace::le);
                            break;
                        case SDLK_LEFT:
                        case SDLK_a:
                            utasitasok.pushEvent(myNspace::balra);
                            break;
                        case SDLK_RIGHT:
                        case SDLK_d:
                            utasitasok.pushEvent(myNspace::jobbra);
                            break;
                        case SDLK_RETURN:
                            utasitasok.pushEvent(myNspace::interakcio);
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
                    utasitasok.pushEvent(myNspace::eger_gorgetes);
                    break;
                case SDL_MOUSEMOTION:
                    myNspace::koordinata xy;
                    SDL_GetMouseState(&(xy.x), &(xy.y));
                    utasitasok.setEger_poz(xy);
                    utasitasok.pushEvent(myNspace::eger_mozgas);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            utasitasok.pushEvent(myNspace::eger_bal_klikk);
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            utasitasok.pushEvent(myNspace::eger_bal_felenged);
                            break;
                    }
                    break;
            }
        }
}

