#ifndef VAGAO_H
#define VAGAO_H

#include <vector>
#include <sstream>

using namespace std;

class Vagao{
public:
    vector<Passageiro*> cadeiras;
    int capacidade;

    Vagao(int capacidade = 20){
        this->capacidade = capacidade;

        for(int i = 0; i < capacidade; i++){
            cadeiras.push_back(nullptr);
        }
    }

    bool embarcar(Passageiro* pass){
        for(auto elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == pass->cpf){
                    throw string("erro | passageiro já embarcado");
                }
            }
        }
        for(int i = 0; i < capacidade; i++){
            if(cadeiras[i] == nullptr){
                cadeiras[i] = pass;
                return true;
            }
        }
        return false;
    }

    bool desembarcar(string cpf){
        for(auto &elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == cpf){
                    elem = nullptr;
                    return true;
                }
            }
        }
        return false;
    }

    string search(string cpf){
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
    }

    string toString(){
        stringstream ss;
        int i = 0;
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

#endif // VAGAO_H
