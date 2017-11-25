#ifndef SALA_H
#define SALA_H

#include <vector>
#include <sstream>
#include "sessao.h"

using namespace std;

int idSala = 0;

struct Sala{
    int capacidade;
    int id;
    bool td;

    Sala(int capacidade = 3 , int td = 0){
        this->capacidade = capacidade;
        this->id = idSala++;

        if(td){
            this->td = true;
        }
        else{
            this->td = false;
        }
    }
};

#endif // SALA_H
