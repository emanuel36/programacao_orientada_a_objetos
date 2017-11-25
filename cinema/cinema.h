#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <sstream>
#include "cliente.h"
#include "sessao.h"
#include "sala.h"
#include <list>
using namespace std;

class Cinema{
public:
    list<Sessao> sessoes;
    list<Sala> salas;
    list<Filme> filmes;

    Cinema(){

    }

   string search(string search){
        stringstream ss;
        ss << "";
        for(auto elem: sessoes){
            ss << elem.search(search);
        }
        if(ss.str() == ""){
            return "erro | nenhuma sessão encontrada";
        }else{
            return ss.str();
        }
    }

    void addSessao(string filme, Sessao sessao, int idS){
        for(auto &elem: salas){
            if(idS == elem.id){
                sessao.sala = &elem;
                sessao.initCadeiras();
                for(auto &eleme: filmes){
                    if(eleme.nome == filme){
                        if(elem.td == eleme.td){
                            sessao.filme = &eleme;
                            sessoes.push_back(sessao);
                            return;
                        }
                        else throw string("erro | sala incompativel");
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
                throw string("erro | sessão lotada");
            }
        }
        throw string("erro | sessão não localizada");
    }

    void finalizarSessao(int sessaoId){

         auto it1 = sessoes.begin();
        for(auto &elem: sessoes){
            if(elem.id == sessaoId){
                sessoes.erase(it1);
                return;
            }
            advance(it1, 1);
        }
        throw string ("erro | sessão não encontrada");
    }

    string showSalas(){
        stringstream ss;
        ss << "";
        for(auto elem: salas){
            ss << "[Sala " << elem.id << "]: " << elem.capacidade << endl;
            if(elem.td){
                ss << "Sala 3D";
            }else{
                ss << "Sala 2D";
            }
            ss << endl;
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
            throw string("erro | sessão não encontrada");
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
            throw string ("erro | nenhuma sessão cadatrada");
        }
        return ss.str();
    }

};

#endif // CINEMA_H
