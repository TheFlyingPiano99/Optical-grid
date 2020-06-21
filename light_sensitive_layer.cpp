//
// Created by simon on 2020. 06. 18..
//

#include "light_sensitive_layer.h"
#include <iostream>

void Light_sensitive_layer::LightInpact (int x, int y, float s) {
    poynting[x][y] = s;
    poynting_history[x][y].push_back(s);
    if (50 < poynting_history[x][y].size()) {
        poynting_history[x][y].pop_front();
        //std::cout << "Reset t." << std::endl;
    }
    float average = 0;
    size_t i;
    for (i =0; i < poynting_history[x][y].size(); i++) {
        average += poynting_history[x][y][i];
    }
    intensity[x][y] = average / (float)i;
}

void Light_sensitive_layer::plot2D (SDL_Renderer* renderer, int x1, int y1, int x2, int y2, float dimming) {

    size_t x_size = intensity.getRowN();
    size_t y_size = intensity.getColumnN();

    SDL_Rect pixel;
    pixel.w = (x2 - x1) / x_size;
    pixel.h = pixel.w;


    for (size_t x = 0; x < x_size; x++) {
        for (size_t y = 0; y < y_size; y++) {
            int color = ((intensity[x][y] * dimming) < 255) ? (intensity[x][y] * dimming) : 255;
            SDL_SetRenderDrawColor(renderer, color * 0.5, color, color * 0.25, 255);

            pixel.x = x1 + x * pixel.w;
            pixel.y = y1 + y * pixel.h;

            SDL_RenderFillRect(renderer, &pixel);
        }
    }
}

void Light_sensitive_layer::plot1D (SDL_Renderer* renderer, Writer* wr, int x1, int y1, int x2, int y2) {

    size_t size_x = intensity.getRowN();
    size_t size_y = intensity.getColumnN();
    size_t y;
    if (size_y > 1) {
        y = size_y/2;
    }
    else if (size_y == 1) {
        y = 0;
    }

    float max_disp_intensity = 200;

    float plot_x_increment = (x2 - x1) / (float)size_x;
    float plot_y_increment = (y2 - y1) / max_disp_intensity;



    //Tengelyek:
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    ///tg(alpha) * l:
    SDL_RenderDrawLine(renderer, x1, y2, x2, y2);
    ///Intenzitás:
    SDL_RenderDrawLine(renderer, x1, y1, x1, y2);
    ///Intenzitás beosztás:
    int y_plot = y2;
    for (size_t i = 0; max_disp_intensity > i; i++) {
        if (i % 50 == 0) {
            y_plot = y2 - i * plot_y_increment;

            SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
            SDL_RenderDrawLine(renderer, x1, y_plot, x2, y_plot);

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, x1, y_plot, x1 + 10, y_plot);


            wr->szoveg_kiir(renderer, std::to_string(i).c_str(), x1 + 10, y_plot, 200);
        }
    }
    wr->szoveg_kiir(renderer, "W/m^2", x1 + 20, y1 + 20, 200);
    wr->szoveg_kiir(renderer, "m", x2 - 20, y2+5, 50);


    int prev_plot_x = x1;
    int prev_plot_y = y2;

    int prev_poy_plot_x = x1;
    int prev_poy_plot_y = y2;

    for (size_t x = 0; x < size_x; x++) {
/*        float avarage = 0;
        int i = 0;
        for (size_t y = 0; y < size_y; y++) {
            avarage += poynting[x][y];
            i++;
        }
        avarage /= (float)i;
*/
        //Poynting:
        int plot_x = x * plot_x_increment;
        int plot_y = y2 - (float)(poynting[x][y] * plot_y_increment);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderDrawLine(renderer, prev_poy_plot_x, prev_poy_plot_y, plot_x, plot_y);

        prev_poy_plot_x = plot_x;
        prev_poy_plot_y = plot_y;

        plot_y = y2 - (float)(intensity[x][y] * plot_y_increment);

        ///Frotier:
        /*if (frotier[x] < poynting[x][y]) {
            frotier[x] = poynting[x][y];
        }
        else if (frotier[x] > poynting[x][y]) {
            frotier[x] *= 0.99;
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, prev_plot_x, y2 - ((0 < x)? frotier[x-1] : frotier[x]) * plot_y_increment, plot_x, y2 - frotier[x]* plot_y_increment);
        */
        ///------------

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawLine(renderer, prev_plot_x, prev_plot_y, plot_x, plot_y);
        prev_plot_x = plot_x;
        prev_plot_y = plot_y;




        //Tengely beosztas:
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        int scale_x = int(x) - (int)(size_x / 2);
        if (scale_x % 10 == 0) {
            SDL_RenderDrawLine(renderer, plot_x, y2, plot_x, y2+5);
            if (scale_x % 25 == 0) {
                SDL_RenderDrawLine(renderer, plot_x, y2, plot_x, y2+10);
                wr->szoveg_kiir(renderer, std::to_string(scale_x * m_per_dot).c_str(), plot_x, y2+10, 100);
            }
        }
    }

}
