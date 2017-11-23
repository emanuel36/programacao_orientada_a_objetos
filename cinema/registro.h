#ifndef REGISTRO_H
#define REGISTRO_H

#include <vector>
#include <list>
#include <sstream>
#include "cliente.h"

using namespace std;

class Registro{
public:
    list<Cliente> cadastro;

    Registro(){

    }

    Cliente* search(string cpf){
        for(auto &elem: cadastro){
            if(elem.cpf == cpf){
                return &elem;
            }
        }
        return nullptr;
    }

    bool cadastrar(Cliente cli){
        for(auto elem: cadastro){
            if(elem.cpf == cli.cpf){
                return false;
            }
        }
        cadastro.push_back(cli);
        return true;
    }

    string getCadastro(){
        stringstream ss;
        for(auto elem: cadastro){
            ss << "[" << elem.cpf << "]" << endl;
        }
        return ss.str();
    }
};

#endif // REGISTRO_H
