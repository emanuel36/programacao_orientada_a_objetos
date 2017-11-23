#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <vector>
#include <sstream>
#include "conta.h"

using namespace std;

int num = 0;

class Operacao{
public:
    string descricao;
    float valor;
    float saldoParcial;

    Operacao(string descricao, float valor, float saldoParcial){
        this->descricao = descricao;
        this->valor = valor;
        this->saldoParcial = saldoParcial;
    }
};

class Conta{
public:
    float saldo;
    int numero;
    vector<Operacao> extrato;
    bool ativa;

    Conta(){
        this->saldo = 0;
        this->numero = num++;
        ativa = true;
    }

    void depositar(float value){
        this->saldo += value;
        extrato.push_back(Operacao("Depósito", value, saldo));
    }

    void sacar(float value){
        if(value > this->saldo){
            throw string ("erro | saldo insuficiente");
        }
        saldo -= value;
    }

    void encerrar(){
        if(!ativa){
            throw string("erro | conta já inativa");
        }
    }

    string getExtrato(){
        stringstream ss;
        for(auto temp: extrato){
            ss << "[" << temp.descricao << "]" << endl
               << "[Valor]: " << temp.valor << endl
               << "[Saldo Parcial]: " << temp.saldoParcial << endl;
        }
        return ss.str();
    }
};

#endif // CONTA_H
