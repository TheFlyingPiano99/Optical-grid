#ifndef KEZELES_H_INCLUDED
#define KEZELES_H_INCLUDED

#include "sajat_tipusok.h"
#include "memtrace.h"
#include <queue>
#define MEMTRACE



class ControlEvents {
    std::queue<myNspace::uzenet> uzenetek;
    myNspace::utasitas_enum utasitas_l[30];
    int i_aktualis;
    myNspace::koordinata eger_poz;
    int rel_eger_gorgetes;

    public:
        ControlEvents() {
            for (int i = 0; i < 30; i++) {
                utasitas_l[i] = myNspace::nincs_utasitas;
            }
            i_aktualis = 0;
            eger_poz = {0,0};
            rel_eger_gorgetes = 0;
        }

        void setEger_poz(myNspace::koordinata& poz) {
            eger_poz = poz;
        }

        const myNspace::koordinata& getEger_poz() {
            return eger_poz;
        }

        void pushEvent(myNspace::utasitas_enum uj) {
            if (30 == i_aktualis) {
                return;
            }
            utasitas_l[i_aktualis++] = uj;
        }

        bool readEvent(myNspace::utasitas_enum* ebbe) {
            *ebbe =  utasitas_l[i_aktualis];
            utasitas_l[i_aktualis] = myNspace::nincs_utasitas;
            if (0 < i_aktualis) {
                i_aktualis--;
            }
            return (*ebbe != myNspace::nincs_utasitas);
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

        void pushEvent(myNspace::uzenet uzenet) {
            uzenetek.push(uzenet);
        }

        myNspace::uzenet readEvent() {
            myNspace::uzenet visszateres = uzenetek.front();
            uzenetek.pop();
            return visszateres;
        }

        std::queue<myNspace::uzenet>& getEvents() {
            return uzenetek;
        }

};




#endif // KEZELES_H_INCLUDED
