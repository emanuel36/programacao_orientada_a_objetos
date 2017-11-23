#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <sstream>
#include "cliente.h"
#include "sala.h"

using namespace std;

class Cinema{
public:
    vector<Sala> salas;

    Cinema(){

    }

   string searchSecao(string hora){
        stringstream ss;
        ss << "";
        for(auto elem: salas){
            ss << elem.searchSecao(hora);
        }
        if(ss.str() == ""){
            return "erro | nenhuma seção encontrada";
        }else{
            return ss.str();
        }
    }

   string searchFilme(string search){
       string temp;
       stringstream ss;
       for(auto elem: salas){
           temp = elem.filme;
           if(temp.find(search)){//erro
               ss << elem.toString();
           }
       }
       return ss.str();
   }

    void addSala(Sala sala){
        salas.push_back(sala);
    }

    void comprar(Cliente *cli, int idSala){
        for(auto &elem: salas){
            if(elem.id == idSala){
                if(elem.comprar(cli)){
                    return;
                }
                throw string("erro | sala lotada");
            }
        }
        throw string("erro | sala não localizada");
    }

    void finalizarSecao(int salaId){
        int i;
        for(auto &elem: salas){
            if(elem.id == salaId){
                salas.erase(salas.begin() + i);
                return;
            }
            i++;
        }
        throw string ("erro | seção não encontrada");
    }

/*    string search(string cpf){
        stringstream ss;
        int i = 0;
        for(auto elem: salas){
            string temp = elem.search(cpf);
            if(temp != "404"){
                ss << "### Sala " << i << " ###" << endl;
                ss << temp;
                return ss.str();
            }
            i++;
        }
        return "erro | passageiro não embarcado";
    }*/

    string toString(){
        stringstream ss;
        ss << "";
        for(auto &elem: salas){
            ss << elem.toString();
        }
        if(ss.str() == ""){
            throw string ("erro | nenhuma sala cadatrada");
        }
        return ss.str();
    }

};

#endif // CINEMA_H
