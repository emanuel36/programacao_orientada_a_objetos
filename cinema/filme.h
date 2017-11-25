#ifndef FILME_H
#define FILME_H


using namespace std;

struct Filme{
    string nome;
    int duracao;
    bool td;


    Filme(string nome, int duracao, int td){
        this->nome = nome;
        this->duracao = duracao;
        if(td) this->td = true;
        else this->td = false;
    }


};

#endif // FILME_H
