#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

struct Cliente{
    string cpf;
    int idade;

    Cliente(string cpf){
        this->cpf = cpf;
    }
};


#endif // CLIENTE_H
