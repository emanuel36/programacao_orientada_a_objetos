#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <sstream>
#include "cliente.h"
#include "secao.h"

using namespace std;

class Cinema{
public:
    vector<Secao> secoes;

    Cinema(){

    }

   string search(string search){
        stringstream ss;
        ss << "";
        for(auto elem: secoes){
            ss << elem.search(search);
        }
        if(ss.str() == ""){
            return "erro | nenhuma seção encontrada";
        }else{
            return ss.str();
        }
    }

    void addSala(Secao secao){
        secoes.push_back(secao);
    }

    void vender(Cliente *cli, int idSecao){
        for(auto &elem: secoes){
            if(elem.id == idSecao){
                if(elem.vender(cli)){
                    return;
                }
                throw string("erro | sala lotada");
            }
        }
        throw string("erro | sala não localizada");
    }

    void finalizarSecao(int salaId){
        int i;
        for(auto &elem: secoes){
            if(elem.id == salaId){
                secoes.erase(secoes.begin() + i);
                return;
            }
            i++;
        }
        throw string ("erro | seção não encontrada");
    }

    string showSecao(int idS){
        stringstream ss;
        ss << "";
        for(auto elem: secoes){
            if(elem.id == idS){
                ss << elem.toString2();
            }
        }
        if(ss.str() == ""){
            throw string("erro | secão não encontrada");
        }
        return ss.str();
    }

    string toString(){
        stringstream ss;
        ss << "";
        for(auto elem: secoes){
            ss << elem.toString();
        }
        if(ss.str() == ""){
            throw string ("erro | nenhuma sala cadatrada");
        }
        return ss.str();
    }

};

#endif // CINEMA_H
