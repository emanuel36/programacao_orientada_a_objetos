#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <sstream>
#include "cliente.h"
#include "sessao.h"
#include "sala.h"

using namespace std;

class Cinema{
public:
    vector<Sessao> sessoes;
    vector<Sala> salas;

    Cinema(){

    }

   string search(string search){
        stringstream ss;
        ss << "";
        for(auto elem: sessoes){
            ss << elem.search(search);
        }
        if(ss.str() == ""){
            return "erro | nenhuma seção encontrada";
        }else{
            return ss.str();
        }
    }

    void addSessao(Sessao sessao, int id){
        for(auto &elem: salas){
            if(id == elem.id){
                sessao.sala = &elem;
                sessoes.push_back(sessao);
                return;
            }
        }
        throw string ("erro | sala não encontrada");
    }

    void addSala(Sala sala){
        salas.push_back(sala);
    }

    void vender(Cliente *cli, int idSessao){
        for(auto &elem: sessoes){
            if(elem.id == idSessao){
                if(elem.vender(cli)){
                    return;
                }
                throw string("erro | secao lotada");
            }
        }
        throw string("erro | secao não localizada");
    }

    void finalizarSessao(int sessaoId){
        int i;
        for(auto &elem: sessoes){
            if(elem.id == sessaoId){
                sessoes.erase(sessoes.begin() + i);
                return;
            }
            i++;
        }
        throw string ("erro | seção não encontrada");
    }

    string showSalas(){
        stringstream ss;
        ss << "";
        for(auto elem: salas){
            ss << "[Sala " << elem.id << "]: " << elem.capacidade << endl;
        }
        if(ss.str() == ""){
            throw string ("erro | nenhuma sala cadastrada");
        }
        return ss.str();
    }

    string showSessao(int idS){
        stringstream ss;
        ss << "";
        for(auto elem: sessoes){
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
        for(auto elem: sessoes){
            ss << elem.toString();
        }
        if(ss.str() == ""){
            throw string ("erro | nenhuma secao cadatrada");
        }
        return ss.str();
    }

};

#endif // CINEMA_H
