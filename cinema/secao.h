#ifndef SECAO_H
#define SECAO_H

#include <vector>
#include <sstream>
#include "cliente.h"

using namespace std;

int i = 0;
class Secao{
public:
    string filme;
    string hora;
    int id;
    vector<Cliente*> cadeiras;
    int capacidade = 3;

    Secao(string filme = "", string hora = ""){
        this->filme = filme;
        this->hora = hora;
        this->id = i++;

        for(int i = 0; i < capacidade; i++){
            cadeiras.push_back(nullptr);
        }
    }

    string search(string search){
        string temp;
        if(this->hora == search || this->filme == search){
            temp = this->toString();
            return temp;
        }
    }

    bool vender(Cliente* cli){
        for(auto elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == cli->cpf){
                    throw string("erro | cliente já comprou");
                }
            }
        }
        for(int i = 0; i < capacidade; i++){
            if(cadeiras[i] == nullptr){
                cadeiras[i] = cli;
                return true;
            }
        }
        return false;
    }

    string toString(){
        stringstream ss;
        int i = 0;
        ss << endl << "### Seção " << id << " ###" << endl;
        ss << "Filme: " << filme << endl;
        ss << "Seção: " << hora << endl;
        for(auto elem: cadeiras){
            if(elem == nullptr){
                i++;
            }
        }
        ss << "Vagas: " << i << endl;
        return ss.str();
    }

    string toString2(){
        stringstream ss;
        ss << endl << "### Seção " << id << " ###" << endl;
        ss << "Filme: " << filme << endl;
        ss << "Seção: " << hora << endl;
        for(auto elem: cadeiras){
            if(elem != nullptr){
                ss << "[" << elem->cpf << "]" << endl;
            }
        }
        return ss.str();
    }
};

#endif // SECAO_H
