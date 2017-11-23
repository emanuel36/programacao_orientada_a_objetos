#ifndef AGENCIA_H
#define AGENCIA_H

using namespace std;

#include <iostream>
#include <vector>
#include "cliente.h"

class Agencia{
public:
    vector<Cliente> clientes;

    Agencia(){

    }

    void addCliente(string cpf){
        for(auto temp: clientes){
            if(temp.cpf == cpf){
                throw string("erro | cpf já é cliente");
            }
        }
        clientes.push_back(Cliente(cpf));
    }

    void abrirConta(string cpf){
        for(auto &temp: clientes){
            if(temp.cpf == cpf){
                temp.addConta();
                return;
            }
        }
        throw string("erro | cliente não existe");
    }

    string getClientes(){
        stringstream ss;
        for(auto temp: clientes){
            ss << endl << temp.getCliente();
        }
        return ss.str();
    }

    Cliente* getCliente(string cpf){
        for(auto &temp: clientes){
            if(temp.cpf == cpf){
                return &temp;
            }
        }
        return nullptr;
    }

};

#endif // AGENCIA_H
