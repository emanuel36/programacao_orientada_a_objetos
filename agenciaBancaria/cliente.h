#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "conta.h"

using namespace std;

class Cliente{
public:
    string cpf;
    vector<Conta> contas;

    Cliente(string cpf){
        this->cpf = cpf;
    }

    void addConta(){
        contas.push_back(Conta());
    }

    void encerrarConta(int numero){
        for(auto &temp: contas){
            if(temp.numero == numero){
                temp.ativa = false;
                return;
            }
        }
        throw string ("erro | conta não existe");
    }

    string getCliente(){
        stringstream ss;
        ss << "[" << cpf << "]" << endl
           << " ### Contas ###" << endl;
        for(auto temp: contas){
            ss << "[" << temp.numero << "]" << endl;
        }
        return ss.str();
    }

    Conta * buscaConta(int num){
        for(auto &elem: contas){
            if(elem.numero == num){
                return &elem;
            }
        }
        throw string ("erro | conta inexistente");
    }

};

#endif // CLIENTE_H
