#ifndef KEZELES_H_INCLUDED
#define KEZELES_H_INCLUDED

#include "my_types.h"
#include "memtrace.h"
#include <queue>
#define MEMTRACE



class ControlEvents {
    std::queue<my::event> uzenetek;
    my::control_event_enum utasitas_l[30];
    int i_aktualis;
    my::int_2d_coord eger_poz;
    int rel_eger_gorgetes;

    public:
        ControlEvents() {
            for (int i = 0; i < 30; i++) {
                utasitas_l[i] = my::nincs_utasitas;
            }
            i_aktualis = 0;
            eger_poz = {0,0};
            rel_eger_gorgetes = 0;
        }

        void setEger_poz(my::int_2d_coord& poz) {
            eger_poz = poz;
        }

        const my::int_2d_coord& getEger_poz() {
            return eger_poz;
        }

        void pushEvent(my::control_event_enum uj) {
            if (30 == i_aktualis) {
                return;
            }
            utasitas_l[i_aktualis++] = uj;
        }

        bool readEvent(my::control_event_enum* ebbe) {
            *ebbe =  utasitas_l[i_aktualis];
            utasitas_l[i_aktualis] = my::nincs_utasitas;
            if (0 < i_aktualis) {
                i_aktualis--;
            }
            return (*ebbe != my::nincs_utasitas);
        }

        bool not_empty() {
            return !uzenetek.empty();
        }

        void eger_gorgetes(int y) {
            rel_eger_gorgetes = y;
        }

        int getEger_gorgetes() {
            return rel_eger_gorgetes;
        }

        void pushEvent(my::event uzenet) {
            uzenetek.push(uzenet);
        }

        my::event readEvent() {
            my::event visszateres = uzenetek.front();
            uzenetek.pop();
            return visszateres;
        }

        std::queue<my::event>& getEvents() {
            return uzenetek;
        }

};




#endif // KEZELES_H_INCLUDED
