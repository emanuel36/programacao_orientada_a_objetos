#ifndef SALA_H
#define SALA_H

#include <vector>
#include <sstream>
#include "cliente.h"

using namespace std;

int i = 0;
class Sala{
public:
    string filme;
    string hora;
    int id;
    vector<Cliente*> cadeiras;
    int capacidade = 3;

    Sala(string filme = "", string hora = ""){
        this->filme = filme;
        this->hora = hora;
        this->id = i++;

        for(int i = 0; i < capacidade; i++){
            cadeiras.push_back(nullptr);
        }
    }

    string searchSecao(string hora){
        string temp;
        if(this->hora == hora){
            temp = this->toString();
            return temp;
        }
    }

    bool comprar(Cliente* cli){
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

    bool finalizarSecao(){
        for(auto &elem: cadeiras){
            elem = nullptr;
        }
        return false;
    }

/*    string search(string cpf){
        stringstream ss;
        int i = 0;
        for(auto elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == cpf){
                    ss << "[Cadeira " << i << "]: " << elem->cpf << endl;
                    return ss.str();
                }
            }
            i++;
        }
        return "404";
    }*/

    string toString(){
        stringstream ss;
        int i = 0;
        ss << endl << "### Sala " << id << " ###" << endl;
        ss << ">>> Filme: " << filme << " <<<" << endl;
        ss << "Seção: " << hora << endl;
        for(auto elem: cadeiras){
            if(elem != nullptr){
                ss << "[Cadeira " << i++ << "]: " << elem->cpf << endl;
            }else{
                ss << "[Cadeira " << i++ << "]: " << "Vazio" << endl;
            }

        }
        return ss.str();
    }
};

#endif // SALA_H
