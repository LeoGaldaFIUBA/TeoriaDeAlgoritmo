#include "FuerzaBruta.h"

FuerzaBruta::FuerzaBruta() {
}

FuerzaBruta::~FuerzaBruta() {        
}

void FuerzaBruta::generarEnvolturaConvexa(){    
    for (auto elem : this->puntosSeguros) {
        for(auto elem2 : this->puntosSeguros){
            if(elem.distinto(elem2)){
                bool todosLosPuntosEstanALaDerecha = true;
                for(auto elem3 : this->puntosSeguros){
                    if(elem3.distinto(elem) && elem3.distinto(elem2)){
                        if(this->area(elem,elem2,elem3) < 0){
                            todosLosPuntosEstanALaDerecha = false;
                        }
                    }
                }
                if (todosLosPuntosEstanALaDerecha){
                    this->envolturaConvexa[elem] = elem2;            
                }
            }
        }
    }
}

int FuerzaBruta::area(Punto p1, Punto p2, Punto p3){    
    return ((p3.getX() - p1.getX()) * (p2.getY() - p1.getY()) -
           ((p3.getY() - p1.getY()) * (p2.getX() - p1.getX())));
}


