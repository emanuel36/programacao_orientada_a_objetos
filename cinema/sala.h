#ifndef SALA_H
#define SALA_H

#include <vector>
#include <sstream>
#include "sessao.h"

using namespace std;

int idSala = 0;

struct Sala{
    int capacidade;
    vector<Cliente*> cadeiras;
    int id;

    Sala(int capacidade = 3){
        this->capacidade = capacidade;
        this->id = idSala++;

        for(int i = 0; i < capacidade; i++){
            cadeiras.push_back(nullptr);
        }
    }
};

#endif // SALA_H
