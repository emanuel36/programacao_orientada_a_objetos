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
    vector<Filme> filmes;

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

    void addSessao(string filme, Sessao sessao, int idS){
        for(auto &elem: salas){
            if(idS == elem.id){
                sessao.sala = &elem;
                for(auto &elem: filmes){
                    if(elem.nome == filme){
                        sessao.filme = &elem;
                        sessoes.push_back(sessao);
                        return;
                    }
                }
                throw string ("erro | filme não encontrado");
            }
        }
        throw string ("erro | sala não encontrada");
    }

    void addSala(Sala sala){
        salas.push_back(sala);
    }

    void addFilme(Filme filme){
        filmes.push_back(filme);
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

    string showFilmes(){
        stringstream ss;
        ss << "";
        for(auto elem: filmes){
            ss << "Filme: " << elem.nome << endl;
            ss << "Duração: " << elem.duracao << " minutos" << endl;
            ss << "3D: ";
            if(elem.td) ss << "Sim";
            else ss << "Não";
            ss << endl;
        }
        if(ss.str() == ""){
            throw string ("erro | nenhum filme cadastrado");
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
