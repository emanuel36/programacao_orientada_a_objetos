#ifndef TREM_H
#define TREM_H

#include <vector>
#include <sstream>

using namespace std;

class Trem{
public:
    int maxVagoes;
    vector<Vagao> vagoes;

    Trem(int maxVagoes = 5){
        this->maxVagoes = maxVagoes;
    }

    void addVagao(Vagao vagao){
        if(vagoes.size() == maxVagoes){
            throw string("erro | capacidade de vagões excedida");
        }
        vagoes.push_back(vagao);
    }

    void embarcar(Passageiro *pass){
        for(auto &elem: vagoes){
            if(elem.embarcar(pass)){
                return;
            }
        }
        throw string("erro | trem lotado até a tampa");
    }

    void desembarcar(string cpf){
        for(auto &elem: vagoes){
            if(elem.desembarcar(cpf)){
                return;
            }
        }
        throw string("erro | passageiro não embarcado");
    }

    string search(string cpf){
        stringstream ss;
        int i = 0;
        for(auto elem: vagoes){
            string temp = elem.search(cpf);
            if(temp != "404"){
                ss << "### Vagão " << i << " ###" << endl;
                ss << temp;
                return ss.str();
            }
            i++;
        }
        return "erro | passageiro não embarcado";
    }

    string toString(){
        stringstream ss;
        int i = 0;
        for(auto &elem: vagoes){
            ss << endl << "### Vagão " << i++ << " ###" << endl;
            ss << elem.toString();
        }
        return ss.str();
    }

};

#endif // TREM_H
