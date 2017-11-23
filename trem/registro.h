#ifndef REGISTRO_H
#define REGISTRO_H

#include <vector>
#include <list>
#include <sstream>

using namespace std;

class Registro{
public:
    list<Passageiro> cadastro;

    Registro(){

    }

    Passageiro* search(string cpf){
        for(auto &elem: cadastro){
            if(elem.cpf == cpf){
                return &elem;
            }
        }
        return nullptr;
    }

    bool cadastrar(Passageiro pass){
        for(auto elem: cadastro){
            if(elem.cpf == pass.cpf){
                return false;
            }
        }
        cadastro.push_back(pass);
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
