//
// Created by simon on 2020. 06. 18..
//

#include "main_loop.h"

#include "resource.h"
#include "maintainer.h"
#include "light_source.h"
#include "optical_grid.h"
#include "light_sensitive_layer.h"
#include "time.h"

InitError::InitError() :
        exception(),
        msg( SDL_GetError() )
{
}

InitError::InitError( const std::string & m ) :
        exception(),
        msg( m )
{
}

InitError::~InitError() throw()
{
}


const char * InitError::what() const throw()
{
    return msg.c_str();
}

//----------------------------------------------------------------




/**A fő ciklus függvénye.
*/
void Main::main_loop (SDL& sdl, Writer& wr) {
    //Init:
    ControlEvents controlEvents;    ///Billentyűzet lenyomásokat tároló objektum.

    Maintainer maintainer(&sdl);    ///A képrenyő frissítéséért felelős objektum.

    //Time time = Time();


    int n = 4;               ///rések száma a rácson
    float wl = 0.0000060;    ///forrás hullámhossz [m]
    float i = 2.0;           ///forrás intenzitása [W/m^2]
    float d = 0.001;         ///távolság a rések között [m]
    float z = 0.5;             ///távolság a rács és fényérzékeny felület között [m]
    float t_spent = 0;       ///idő változó

    ///Fényérzékeny réteg inicializálása (300x40 pixel és 0.01 méter / pixel oldal):
    Light_sensitive_surface light_surface(300, 40, 0.001);

    ///Lézer inicializálása:
    Laser laser(wl, i);

    ///tényleges ciklus:
    bool fut = true;
    while (fut) {
        maintainer.clearScreen();

        //time.calculate();
        t_spent =  t_spent + (float)0.00000001;

        ///Fölöslegesen nagy eltelt idő helyett nullázom:
        if (6.2831853 < t_spent) {
            t_spent = 0;
            //std::cout << "Reset t." << std::endl;
        }

        Optical_grid grid(n, d);   ///Optikai rács inicializálása

        ///Diffrakció végrehajtása lézerfényen z távolságban lévő felületre vetítve:
        grid.diffract(&laser, z, &light_surface, t_spent);

        ///Ábrák kirajzolása:
        light_surface.plot1D(sdl.getRenderer(), &wr, 0, 0, my::window_width, my::window_height - 100,
                40, 2);
        light_surface.plot2D(sdl.getRenderer(), 80, 0, my::window_width, my::window_height, 10);

        ///Értékek kiírása:
        std::string str;
        str.append("slit number = ");
        str.append(std::to_string(n));
        str.append(";");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 10, my::window_height - 70, my::window_width);

        str.clear();
        str.append("slit distance = ");
        str.append(std::to_string(d));
        str.append(" m;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 10, my::window_height - 50, my::window_width);

        str.clear();
        str.append("light_surface distance = ");
        str.append(std::to_string(z));
        str.append(" m;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 10, my::window_height - 30, my::window_width);

        str.clear();
        str.append("source wavelength = ");
        str.append(std::to_string(laser.getWavelength()));
        str.append(" m;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 500, my::window_height - 70, my::window_width);

        str.clear();
        str.append("source intensity = ");
        str.append(std::to_string(laser.getIntensity()));
        str.append(" W/m^2;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 500, my::window_height - 50, my::window_width);

        maintainer.display();

        ///Billentyűzet bemenet kezelése:
        sdl.billentyu_olvasas(controlEvents);
        my::control_event_enum utas;
        while (controlEvents.readEvent(&utas)) {
            switch (utas) {
                case my::control_event_enum::fel:
                    n++;
                    break;
                case my::control_event_enum::le:
                    if (n > 0) {
                        n--;
                    }
                    break;
                case my::control_event_enum::jobbra:
                    d+= 0.00001;
                    break;
                case my::control_event_enum::balra:
                    d-= 0.00001;
                    break;
                case my::control_event_enum::kilep:
                    fut = false;
                    break;
                default:
                    break;
            }
        }
    }

}




/**
Fő függvény.

Itt inicializálódik az SDL ablak.
Elő inicializálás.
Ebből hívódik a fő ciklus.
*/
int Main::main_func( int argc, char * argv[] ) {
    ///SDL Inicializacio:
    SDL *sdl = NULL;
    try
    {
        sdl = new SDL( SDL_INIT_VIDEO | SDL_INIT_TIMER );
    }
    catch ( const InitError & err )
    {
        std::cerr << "Error az SDL inicializa'la'sa ko:zben:  "
                  << err.what()
                  << std::endl;
        if (NULL != sdl) {
            delete sdl;
        }
        return 1;
    }

    Writer wr = Writer();       ///szöveg kiírásért felelős objektum
    wr.beolvas_bmp_font(sdl);

    ///Fő ciklus:
    main_loop (*sdl, wr);

    ///Felszabadítás:
    delete sdl;

    return 0;
}
