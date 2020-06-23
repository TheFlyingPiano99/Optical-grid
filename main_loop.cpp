//
// Created by simon on 2020. 06. 18..
//

#include "main_loop.h"

#include "resource.h"
#include "maintainer.h"
#include "light_source.h"
#include "optical_grid.h"
#include "light_sensitive_layer.h"
#include "ido.h"

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




/**A fő ciklus.

*/
void Main::main_loop (SDL& sdl, Writer& wr) {
    ControlEvents controlEvents;

    Maintainer maintainer(&sdl);

    Ido time = Ido();

    //Init:


    //float ratio = my::window_width / my::window_height;

    //float resolution = 200;
    //float angle = 1;

    //size_t depth = 70;
    //float depth_resolution = 60;
    //float delta_depth = depth / depth_resolution;

    //float angle_offset = (3.14-angle) / 2;
    //float delta_rad = angle / resolution;

    //size_t pixel_per_x = resolution;
    //size_t pixel_per_y = resolution;

    Light_sensitive_layer layer(300, 40, 0.01);

    int n = 10;
    float wl = 0.0000060;
    float d = 0.001;
    float x = 1;
    float t_spent = 0;

    bool fut = true;
    while (fut) {

        time.ido_szamitas();
        t_spent =  t_spent + (float)0.00000001;
        if (6.2831853 < t_spent) {
            t_spent = 0;
            std::cout << "Reset t." << std::endl;
        }


        Laser laser(wl, 2);
        Optical_grid grid(n, d);
        maintainer.clearScreen();

        grid.diffract(&laser, x, &layer, t_spent);

        layer.plot1D(sdl.getRenderer(), &wr, 0, 0, my::window_width, my::window_height - 100);
        layer.plot2D(sdl.getRenderer(), 80, 0, my::window_width, my::window_height, 2);

        ///Értékek kiírása:
        std::string str;
        str.append("n = ");
        str.append(std::to_string(n));
        str.append(";");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 10, my::window_height - 70, my::window_width);
        str.clear();
        str.append("d = ");
        str.append(std::to_string(d));
        str.append(" m;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 10, my::window_height - 50, my::window_width);

        str.clear();
        str.append("source wavelength = ");
        str.append(std::to_string(laser.getWavelength()));
        str.append(" m;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 10, my::window_height - 30, my::window_width);

        str.clear();
        str.append("source intensity = ");
        str.append(std::to_string(laser.getIntensity()));
        str.append(" W/m^2;");
        wr.szoveg_kiir(sdl.getRenderer(), str.c_str(), 500, my::window_height - 30, my::window_width);

        maintainer.display();

        /*
        ///Várakozás billentyűzet-bemenetre:
        bool wait = true;
        while (wait) {
         */
        sdl.billentyu_olvasas(controlEvents);
        my::control_event_enum utas;
        while (controlEvents.readEvent(&utas)) {
            //wait = false;
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
        //}
    }

}




/**
Fő függvény.

Itt inicializálódik az SDL ablak.
Elő inicializálás.
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

    Writer wr = Writer();
    wr.beolvas_bmp_font(sdl);

    main_loop (*sdl, wr);

    ///Felszabadítás:
    delete sdl;

    return 0;
}
